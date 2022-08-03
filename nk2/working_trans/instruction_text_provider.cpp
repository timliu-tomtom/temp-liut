/*
 * Copyright (C) 2019 TomTom NV. All rights reserved.
 *
 * This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
 * used for internal evaluation purposes or commercial use strictly subject to separate
 * license agreement between you and TomTom NV. If you are the licensee, you are only permitted
 * to use this software in accordance with the terms of your license agreement. If you are
 * not the licensee, you are not authorized to use this software in any manner and should
 * immediately return or destroy it.
 */

#include "instruction_text_provider.hpp"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdexcept>

#include <fmt/format.h>
#include <rapidjson/error/en.h>
#include <rapidjson/schema.h>

#include <tomtom/navkit2/log.hpp>

#include "distance_text_generator.hpp"
#include <iostream>

namespace {
constexpr auto kLogId = "navigation-text-generation";
}

namespace tomtom {
namespace navkit2 {
namespace text_generation {
namespace internal {

namespace {

std::unordered_map<std::string, std::string> ParseJson(const std::string& translation_json) {
  std::unordered_map<std::string, std::string> lang_translation_map;
  rapidjson::Document document;
  rapidjson::ParseResult parse_result = document.Parse(translation_json.c_str());
  if (!parse_result || !document.IsObject()) {
    TT_LOG_WARNING(kLogId, "Unable to parse the JSON string, error \"{}\" at {}",
                   GetParseError_En(parse_result.Code()), parse_result.Offset());
    return lang_translation_map;
  }

  for (auto itr = document.MemberBegin(); itr != document.MemberEnd(); ++itr) {
    lang_translation_map.insert({itr->name.GetString(), itr->value.GetString()});
  }

  return lang_translation_map;
}

bool IsTranslationForLocaleAvailable(
    const std::unordered_map<std::string, std::string>& lang_translation_map,
    const std::string& locale) {
  if (lang_translation_map.find(locale) != lang_translation_map.end()) {
    return true;
  }

  TT_LOG_WARNING(
      kLogId, "Translation is not available for language {} hence using the default translation.",
      locale);
  return false;
}

const std::string kDefaultLocale = "en-US";
constexpr auto kDefaultUnitSystem = distance_rounding::UnitSystem::kMetric;
constexpr auto kRoundingSpecification = distance_rounding::RoundingSpecification::kDefault;
}  // namespace

const std::vector<InstructionTextProvider::Rule>& InstructionTextProvider::GetRules() {
  if (rules_.empty()) {
    auto rules = InstructionRulesFactory(*message_translator_).GetRules();
    rules_.swap(rules);
  }
  return rules_;
}

const std::vector<InstructionTextProvider::Rule>&
InstructionTextProvider::GetDirectionDetailsRules() {
  if (direction_details_rules_.empty()) {
    auto rules = InstructionRulesFactory(*message_translator_).GetDirectionDetailsRules();
    direction_details_rules_.swap(rules);
  }
  return direction_details_rules_;
}

InstructionTextProvider::InstructionTextProvider(const std::string& translation_json)
    : lang_translation_map_(ParseJson(translation_json)),
      locale_(kDefaultLocale),
      unit_system_(kDefaultUnitSystem),
      rounding_specification_(kRoundingSpecification) {
  LazyInitCatalog();
}

TranslatedMessage InstructionTextProvider::Translate(const std::string& message_in_english) const {
  assert(message_translator_);
  return message_translator_->Translate(message_in_english);
}

TranslatedMessage InstructionTextProvider::Translate(const std::string& message_in_english,
                                                     const std::string& context) const {
  assert(message_translator_);
  return message_translator_->Translate(message_in_english, context);
}

TranslatedMessage InstructionTextProvider::Translate(
    const std::string& message_in_english_in_singular,
    const std::string& message_in_english_in_plural, long count) const {
  assert(message_translator_);
  return message_translator_->Translate(message_in_english_in_singular,
                                        message_in_english_in_plural, count);
}

TranslatedMessage InstructionTextProvider::Translate(
    const std::string& message_in_english_in_singular,
    const std::string& message_in_english_in_plural, const std::string& context, long count) const {
  assert(message_translator_);
  return message_translator_->Translate(message_in_english_in_singular,
                                        message_in_english_in_plural, context, count);
}

void InstructionTextProvider::LazyInitCatalog() {
  if (!IsTranslationForLocaleAvailable(lang_translation_map_, locale_)) {
    message_translator_ = std::make_unique<MessageTranslator>();
    rules_.clear();
    rules_ = GetRules();
    InitBorderCrossingCountryLookupTable();

    return;
  }

  message_translator_ = std::make_unique<MessageTranslator>(lang_translation_map_, locale_);

  rules_.clear();
  rules_ = GetRules();
  InitBorderCrossingCountryLookupTable();
}

void InstructionTextProvider::InitBorderCrossingCountryLookupTable() {
  // 'the' article was added base on:
  // https://www.engvid.com/english-resource/the-with-country-names-lakes-rivers/
  // https://www.grammar-quizzes.com/article4c.html
  country_lookup_table_["AFG"] = Translate("Afghanistan", "you are entering {country}");
  country_lookup_table_["ALB"] = Translate("Albania", "you are entering {country}");
  country_lookup_table_["DZA"] = Translate("Algeria", "you are entering {country}");
  country_lookup_table_["AND"] = Translate("Andorra", "you are entering {country}");
  country_lookup_table_["AGO"] = Translate("Angola", "you are entering {country}");
  country_lookup_table_["ARG"] = Translate("Argentina", "you are entering {country}");
  country_lookup_table_["ARM"] = Translate("Armenia", "you are entering {country}");
  country_lookup_table_["AUT"] = Translate("Austria", "you are entering {country}");
  country_lookup_table_["AZE"] = Translate("Azerbaijan", "you are entering {country}");
  country_lookup_table_["BHR"] = Translate("Bahrain", "you are entering {country}");
  country_lookup_table_["BGD"] = Translate("Bangladesh", "you are entering {country}");
  country_lookup_table_["BLR"] = Translate("Belarus", "you are entering {country}");
  country_lookup_table_["BEL"] = Translate("Belgium", "you are entering {country}");
  country_lookup_table_["BLZ"] = Translate("Belize", "you are entering {country}");
  country_lookup_table_["BEN"] = Translate("Benin", "you are entering {country}");
  country_lookup_table_["BTN"] = Translate("Bhutan", "you are entering {country}");
  country_lookup_table_["BOL"] = Translate("Bolivia", "you are entering {country}");
  country_lookup_table_["BIH"] = Translate("Bosnia and Herzegowina", "you are entering {country}");
  country_lookup_table_["BWA"] = Translate("Botswana", "you are entering {country}");
  country_lookup_table_["BRA"] = Translate("Brazil", "you are entering {country}");
  country_lookup_table_["BRN"] = Translate("Brunei", "you are entering {country}");
  country_lookup_table_["BGR"] = Translate("Bulgaria", "you are entering {country}");
  country_lookup_table_["BFA"] = Translate("Burkina Faso", "you are entering {country}");
  country_lookup_table_["BDI"] = Translate("Burundi", "you are entering {country}");
  country_lookup_table_["KHM"] = Translate("Cambodia", "you are entering {country}");
  country_lookup_table_["CMR"] = Translate("Cameroon", "you are entering {country}");
  country_lookup_table_["CAN"] = Translate("Canada", "you are entering {country}");
  country_lookup_table_["CAF"] =
      Translate("the Central African Republic", "you are entering {country}");
  country_lookup_table_["TCD"] = Translate("Chad", "you are entering {country}");
  country_lookup_table_["CHL"] = Translate("Chile", "you are entering {country}");
  country_lookup_table_["CHN"] = Translate("China", "you are entering {country}");
  country_lookup_table_["COL"] = Translate("Colombia", "you are entering {country}");
  country_lookup_table_["COG"] =
      Translate("the Republic of the Congo", "you are entering {country}");
  country_lookup_table_["COD"] =
      Translate("the Democratic Republic of the Congo", "you are entering {country}");
  country_lookup_table_["CRI"] = Translate("Costa Rica", "you are entering {country}");
  // checked with native speaker:
  // 1) for US terms for Ivory Coast is more common then Cote d'Ivoire
  // 2) "the" is gone for Ivory Coast
  country_lookup_table_["CIV"] = Translate("Ivory Coast", "you are entering {country}");
  country_lookup_table_["HRV"] = Translate("Croatia", "you are entering {country}");
  country_lookup_table_["CYP"] = Translate("Cyprus", "you are entering {country}");
  country_lookup_table_["CZE"] = Translate("the Czech Republic", "you are entering {country}");
  country_lookup_table_["DNK"] = Translate("Denmark", "you are entering {country}");
  country_lookup_table_["DJI"] = Translate("Djibouti", "you are entering {country}");
  // On that islands are 2 counties, second one is Haiti
  country_lookup_table_["DOM"] = Translate("the Dominican Republic", "you are entering {country}");
  // has border with Indonasia
  country_lookup_table_["TMP"] = Translate("East Timor", "you are entering {country}");
  country_lookup_table_["ECU"] = Translate("Ecuador", "you are entering {country}");
  country_lookup_table_["EGY"] = Translate("Egypt", "you are entering {country}");
  country_lookup_table_["SLV"] = Translate("El Salvador", "you are entering {country}");
  country_lookup_table_["GNQ"] = Translate("Equatorial Guinea", "you are entering {country}");
  country_lookup_table_["ERI"] = Translate("Eritrea", "you are entering {country}");
  country_lookup_table_["EST"] = Translate("Estonia", "you are entering {country}");
  country_lookup_table_["ETH"] = Translate("Ethiopia", "you are entering {country}");
  country_lookup_table_["FIN"] = Translate("Finland", "you are entering {country}");
  country_lookup_table_["FRA"] = Translate("France", "you are entering {country}");
  country_lookup_table_["GUF"] = Translate("French Guiana", "you are entering {country}");
  country_lookup_table_["GAB"] = Translate("Gabon", "you are entering {country}");
  country_lookup_table_["GMB"] = Translate("the Gambia", "you are entering {country}");
  country_lookup_table_["GEO"] = Translate("Georgia", "you are entering {country}");
  country_lookup_table_["DEU"] = Translate("Germany", "you are entering {country}");
  country_lookup_table_["GHA"] = Translate("Ghana", "you are entering {country}");
  country_lookup_table_["GIB"] = Translate("Gibraltar", "you are entering {country}");
  country_lookup_table_["GRC"] = Translate("Greece", "you are entering {country}");
  country_lookup_table_["GTM"] = Translate("Guatemala", "you are entering {country}");
  country_lookup_table_["GIN"] = Translate("Guinea", "you are entering {country}");
  country_lookup_table_["GNB"] = Translate("Guinea-Bissau", "you are entering {country}");
  country_lookup_table_["GUY"] = Translate("Guyana", "you are entering {country}");
  country_lookup_table_["HTI"] = Translate("Haiti", "you are entering {country}");
  country_lookup_table_["VAT"] = Translate("Vatican City", "you are entering {country}");
  country_lookup_table_["HND"] = Translate("Honduras", "you are entering {country}");
  country_lookup_table_["HKG"] = Translate("Hong Kong", "you are entering {country}");
  country_lookup_table_["HUN"] = Translate("Hungary", "you are entering {country}");
  country_lookup_table_["IND"] = Translate("India", "you are entering {country}");
  country_lookup_table_["IDN"] = Translate("Indonesia", "you are entering {country}");
  country_lookup_table_["IRN"] = Translate("Iran", "you are entering {country}");
  country_lookup_table_["IRQ"] = Translate("Iraq", "you are entering {country}");
  country_lookup_table_["IRL"] = Translate("Ireland", "you are entering {country}");
  country_lookup_table_["ISR"] = Translate("Israel", "you are entering {country}");
  country_lookup_table_["ITA"] = Translate("Italy", "you are entering {country}");
  country_lookup_table_["JAM"] = Translate("Jamaica", "you are entering {country}");
  country_lookup_table_["JOR"] = Translate("Jordan", "you are entering {country}");
  country_lookup_table_["KAZ"] = Translate("Kazakhstan", "you are entering {country}");
  country_lookup_table_["KEN"] = Translate("Kenya", "you are entering {country}");
  country_lookup_table_["PRK"] = Translate("North Korea", "you are entering {country}");
  country_lookup_table_["KOR"] = Translate("South Korea", "you are entering {country}");
  country_lookup_table_["XKS"] = Translate("Kosovo", "you are entering {country}");
  country_lookup_table_["KWT"] = Translate("Kuwait", "you are entering {country}");
  country_lookup_table_["KGZ"] = Translate("Kyrgyzstan", "you are entering {country}");
  country_lookup_table_["LAO"] = Translate("Laos", "you are entering {country}");
  country_lookup_table_["LVA"] = Translate("Latvia", "you are entering {country}");
  country_lookup_table_["LBN"] = Translate("Lebanon", "you are entering {country}");
  country_lookup_table_["LSO"] = Translate("Lesotho", "you are entering {country}");
  country_lookup_table_["LBR"] = Translate("Liberia", "you are entering {country}");
  country_lookup_table_["LBY"] = Translate("Libya", "you are entering {country}");
  country_lookup_table_["LIE"] = Translate("Liechtenstein", "you are entering {country}");
  country_lookup_table_["LTU"] = Translate("Lithuania", "you are entering {country}");
  country_lookup_table_["LUX"] = Translate("Luxembourg", "you are entering {country}");
  country_lookup_table_["MAC"] = Translate("Macau", "you are entering {country}");
  country_lookup_table_["MKD"] = Translate("North Macedonia", "you are entering {country}");
  country_lookup_table_["MWI"] = Translate("Malawi", "you are entering {country}");
  country_lookup_table_["MYS"] = Translate("Malaysia", "you are entering {country}");
  country_lookup_table_["MLI"] = Translate("Mali", "you are entering {country}");
  country_lookup_table_["MLT"] = Translate("Malta", "you are entering {country}");
  country_lookup_table_["MRT"] = Translate("Mauritania", "you are entering {country}");
  country_lookup_table_["MEX"] = Translate("Mexico", "you are entering {country}");
  country_lookup_table_["MDA"] = Translate("Moldova", "you are entering {country}");
  country_lookup_table_["MCO"] = Translate("Monaco", "you are entering {country}");
  country_lookup_table_["MNG"] = Translate("Mongolia", "you are entering {country}");
  country_lookup_table_["MNE"] = Translate("Montenegro", "you are entering {country}");
  country_lookup_table_["MAR"] = Translate("Morocco", "you are entering {country}");
  country_lookup_table_["MOZ"] = Translate("Mozambique", "you are entering {country}");
  country_lookup_table_["MMR"] = Translate("Myanmar", "you are entering {country}");
  country_lookup_table_["NAM"] = Translate("Namibia", "you are entering {country}");
  country_lookup_table_["NPL"] = Translate("Nepal", "you are entering {country}");
  country_lookup_table_["NLD"] = Translate("the Netherlands", "you are entering {country}");
  country_lookup_table_["NIC"] = Translate("Nicaragua", "you are entering {country}");
  country_lookup_table_["NER"] = Translate("Niger", "you are entering {country}");
  country_lookup_table_["NGA"] = Translate("Nigeria", "you are entering {country}");
  country_lookup_table_["NOR"] = Translate("Norway", "you are entering {country}");
  country_lookup_table_["OMN"] = Translate("Oman", "you are entering {country}");
  country_lookup_table_["PAK"] = Translate("Pakistan", "you are entering {country}");
  country_lookup_table_["PSE"] = Translate("Palestine", "you are entering {country}");
  country_lookup_table_["PAN"] = Translate("Panama", "you are entering {country}");
  country_lookup_table_["PNG"] = Translate("Papua New Guinea", "you are entering {country}");
  country_lookup_table_["PRY"] = Translate("Paraguay", "you are entering {country}");
  country_lookup_table_["PER"] = Translate("Peru", "you are entering {country}");
  country_lookup_table_["POL"] = Translate("Poland", "you are entering {country}");
  country_lookup_table_["PRT"] = Translate("Portugal", "you are entering {country}");
  country_lookup_table_["QAT"] = Translate("Qatar", "you are entering {country}");
  // 2 entries Romania, as ROM was changed to ROU in Feb 2002
  // according to http://en.wikipedia.org/wiki/ISO_3166-1_alpha-3.
  // Store entry for "ROU" before "ROM", so conversion to 3-letter
  // code will use "ROU" in priority.
  country_lookup_table_["ROU"] = Translate("Romania", "you are entering {country}");
  country_lookup_table_["ROM"] = country_lookup_table_["ROU"];
  country_lookup_table_["RUS"] = Translate("the Russian Federation", "you are entering {country}");
  country_lookup_table_["RWA"] = Translate("Rwanda", "you are entering {country}");
  country_lookup_table_["MAF"] = Translate("Saint Martin", "you are entering {country}");
  country_lookup_table_["SMR"] = Translate("San Marino", "you are entering {country}");
  country_lookup_table_["SAU"] = Translate("Saudi Arabia", "you are entering {country}");
  country_lookup_table_["SEN"] = Translate("Senegal", "you are entering {country}");
  country_lookup_table_["SRB"] = Translate("Serbia", "you are entering {country}");
  country_lookup_table_["SLE"] = Translate("Sierra Leone", "you are entering {country}");
  country_lookup_table_["SGP"] = Translate("Singapore", "you are entering {country}");
  country_lookup_table_["SXM"] = Translate("Sint Maarten", "you are entering {country}");
  country_lookup_table_["SVK"] = Translate("Slovakia", "you are entering {country}");
  country_lookup_table_["SVN"] = Translate("Slovenia", "you are entering {country}");
  country_lookup_table_["SOM"] = Translate("Somalia", "you are entering {country}");
  country_lookup_table_["ZAF"] = Translate("South Africa", "you are entering {country}");
  country_lookup_table_["SSD"] = Translate("South Sudan", "you are entering {country}");
  country_lookup_table_["ESP"] = Translate("Spain", "you are entering {country}");
  country_lookup_table_["SDN"] = Translate("Sudan", "you are entering {country}");
  country_lookup_table_["SUR"] = Translate("Suriname", "you are entering {country}");
  country_lookup_table_["SWZ"] = Translate("Swaziland", "you are entering {country}");
  country_lookup_table_["SWE"] = Translate("Sweden", "you are entering {country}");
  country_lookup_table_["CHE"] = Translate("Switzerland", "you are entering {country}");
  country_lookup_table_["SYR"] = Translate("Syria", "you are entering {country}");
  country_lookup_table_["TJK"] = Translate("Tajikistan", "you are entering {country}");
  country_lookup_table_["TZA"] = Translate("Tanzania", "you are entering {country}");
  country_lookup_table_["THA"] = Translate("Thailand", "you are entering {country}");
  country_lookup_table_["TLS"] = Translate("Timor-Leste", "you are entering {country}");
  country_lookup_table_["TGO"] = Translate("Togo", "you are entering {country}");
  country_lookup_table_["TUN"] = Translate("Tunisia", "you are entering {country}");
  country_lookup_table_["TUR"] = Translate("Turkey", "you are entering {country}");
  country_lookup_table_["TKM"] = Translate("Turkmenistan", "you are entering {country}");
  country_lookup_table_["UGA"] = Translate("Uganda", "you are entering {country}");
  country_lookup_table_["UKR"] = Translate("Ukraine", "you are entering {country}");
  country_lookup_table_["ARE"] =
      Translate("the United Arab Emirates", "you are entering {country}");
  // not sure it is needed
  country_lookup_table_["GBR"] = Translate("the United Kingdom", "you are entering {country}");
  country_lookup_table_["USA"] =
      Translate("the United States of America", "you are entering {country}");
  country_lookup_table_["URY"] = Translate("Uruguay", "you are entering {country}");
  country_lookup_table_["UZB"] = Translate("Uzbekistan", "you are entering {country}");
  country_lookup_table_["VEN"] = Translate("Venezuela", "you are entering {country}");
  country_lookup_table_["VNM"] = Translate("Vietnam", "you are entering {country}");
  country_lookup_table_["ESH"] = Translate("Western Sahara", "you are entering {country}");
  country_lookup_table_["YEM"] = Translate("Yemen", "you are entering {country}");
  country_lookup_table_["ZMB"] = Translate("Zambia", "you are entering {country}");
  country_lookup_table_["ZWE"] = Translate("Zimbabwe", "you are entering {country}");
}

namespace {
std::string Stringify(const InstructionTextProvider::TemplateParameters& params) {
  std::ostringstream ss;
  if (params.type.has_value()) {
    ss << "TemplateParameters{type=" << *params.type;
  }

  ss << ", message_type=" << params.message_type;

  if (!params.distance_text.empty()) {
    ss << ", " << params.distance_text;
  }

  if (!params.road_name.text.empty()) {
    ss << ", road_name=" << params.road_name.text;
  }

  if (!params.road_numbers.empty()) {
    ss << ", road_numbers=";
    std::copy(params.road_numbers.begin(), params.road_numbers.end(),
              std::ostream_iterator<TextWithPhonetic>(ss, ", "));
  }

  if (!params.intersection_name.text.empty()) {
    ss << ", intersection_name=" << params.intersection_name.text;
  }

  if (params.turn_direction.has_value()) {
    ss << ", turn_direction=" << *params.turn_direction;
  }

  if (params.exit_direction.has_value()) {
    ss << ", exit_direction=" << *params.exit_direction;
  }

  if (!params.roundabout_ordinal_exit_number.empty()) {
    ss << ", roundabout_exit_number=" << params.roundabout_ordinal_exit_number;
  }

  if (params.itinerary_point_side != ItineraryPointSide::kUnknown) {
    ss << ", itinerary_point_side=" << params.itinerary_point_side;
  }

  if (params.into_country_name) {
    ss << ", next_country_name=" << *params.into_country_name;
  }

  if (params.auto_transport_type) {
    ss << ", auto_transport_type=" << *params.auto_transport_type;
  }

  if (!params.landmark.empty()) {
    ss << ", landmark=" << params.landmark;
  }

  ss << ", driving_side=" << params.driving_side;

  if (!params.exit_number.text.empty()) {
    ss << ", exit_number=" << params.exit_number.text;
  }

  if (!params.exit_name.text.empty()) {
    ss << ", exit_name=" << params.exit_name.text;
  }

  if (!params.toward_name.text.empty()) {
    ss << ", toward_name=" << params.toward_name.text;
  }

  ss << ", has_signpost=" << params.has_signpost;
  ss << ", verbosity level=" << params.verbosity_level << "}";
  return ss.str();
}
}  // namespace

TranslatedMessage InstructionTextProvider::SelectTemplate(
    const InstructionTextProviderInterface::TemplateParameters& params) {
  const auto rule_applies = [&params](const Rule& rule) -> bool {
    const auto predicates_satisfied =
        std::all_of(rule.predicates.begin(), rule.predicates.end(),
                    [&params](const auto pred) { return pred(params); });
    const auto is_translated = rule.message.is_translated == Translated::kYes;
    const auto has_direction_details =
        rule.message.text.find("{direction_details}") != std::string::npos;

    // temporary solution until all needed messages will be moved to new approach with
    // {direction_details} and all new messages are translated. Ticket to remove: NAV-85554
    return predicates_satisfied && (is_translated || !has_direction_details);
  };

  const auto& rules = GetRules();
  auto rule_it = std::find_if(rules.begin(), rules.end(), rule_applies);
  if (rule_it != rules.end()) {
    //std::cout << "Rule Eng: " << rule_it->message.in_english << "###"<< rule_it->message.ctx << std::endl;
    return rule_it->message;
  }

  throw std::runtime_error("No text generation rule found for template parameters " +
                           Stringify(params));
}

TranslatedMessage InstructionTextProvider::SelectDirectionDetailsTemplate(
    const InstructionTextProviderInterface::TemplateParameters& params) {
  const auto rule_applies = [&params](const Rule& rule) {
    return std::all_of(rule.predicates.begin(), rule.predicates.end(),
                       [&params](const auto pred) { return pred(params); });
  };

  const auto& rules = GetDirectionDetailsRules();
  auto rule_it = std::find_if(rules.begin(), rules.end(), rule_applies);
  if (rule_it != rules.end()) {
    return rule_it->message;
  }

  TT_LOG_WARNING(kLogId, "Rule for DirectionDetails is not found.");
  return TranslatedMessage{"", "en-US", Translated::kNo};
}

TranslatedMessage InstructionTextProvider::TranslateCountryName(
    const TomTom::NavKit::I18n::CISOCountryCode& code) const {
  const auto result_itr = country_lookup_table_.find(code);
  if (result_itr != country_lookup_table_.end() && locale_ == result_itr->second.locale) {
    return result_itr->second;
  }

  TT_LOG_WARNING(kLogId, "No translation for country code: {}", code.c_str());
  return {};
}

TranslatedMessage InstructionTextProvider::TranslateManeuverDistanceFromCentimeters(
    int32_t distance, DistanceContext context) {
  assert(message_translator_);
  const DistanceTextGenerator distance_text_generator(
      locale_, unit_system_, rounding_specification_, *message_translator_);

  return distance_text_generator.TranslateDistance(
      TomTom::NavKit::Quantities::TCentimeters(distance), context);
}

TranslatedMessage InstructionTextProvider::TranslateExitRoundaboutOrdinalNumber(int exit_number) {
  switch (exit_number) {
    case 1:
      return Translate("first", "{roundabout_exit_number}");
    case 2:
      return Translate("second", "{roundabout_exit_number}");
    case 3:
      return Translate("third", "{roundabout_exit_number}");
    case 4:
      return Translate("fourth", "{roundabout_exit_number}");
    case 5:
      return Translate("fifth", "{roundabout_exit_number}");
    case 6:
      return Translate("sixth", "{roundabout_exit_number}");
    case 7:
      return Translate("seventh", "{roundabout_exit_number}");
    case 8:
      return Translate("eighth", "{roundabout_exit_number}");
    case 9:
      return Translate("ninth", "{roundabout_exit_number}");
    case 10:
      return Translate("tenth", "{roundabout_exit_number}");
    case 11:
      return Translate("eleventh", "{roundabout_exit_number}");
    case 12:
      return Translate("twelfth", "{roundabout_exit_number}");
    default:
      TT_LOG_WARNING(kLogId,
                     "exit number for roundabout is only supported in range 1-12. Provided: {}",
                     exit_number);
      return {std::to_string(exit_number), locale_, Translated::kYes};
  }
}

TranslatedMessage InstructionTextProvider::TranslateExitRoundaboutOrdinalNumberV2(int exit_number) {
  switch (exit_number) {
    case 1:
      return Translate("first", "{roundabout_exit_number_v2}");
    case 2:
      return Translate("second", "{roundabout_exit_number_v2}");
    case 3:
      return Translate("third", "{roundabout_exit_number_v2}");
    case 4:
      return Translate("fourth", "{roundabout_exit_number_v2}");
    case 5:
      return Translate("fifth", "{roundabout_exit_number_v2}");
    case 6:
      return Translate("sixth", "{roundabout_exit_number_v2}");
    case 7:
      return Translate("seventh", "{roundabout_exit_number_v2}");
    case 8:
      return Translate("eighth", "{roundabout_exit_number_v2}");
    case 9:
      return Translate("ninth", "{roundabout_exit_number_v2}");
    case 10:
      return Translate("tenth", "{roundabout_exit_number_v2}");
    case 11:
      return Translate("eleventh", "{roundabout_exit_number_v2}");
    case 12:
      return Translate("twelfth", "{roundabout_exit_number_v2}");
    default:
      TT_LOG_WARNING(kLogId,
                     "exit number for roundabout is only supported in range 1-12. Provided: {}",
                     exit_number);
      return {std::to_string(exit_number), locale_, Translated::kYes};
  }
}

TranslatedMessage InstructionTextProvider::TranslateLandmark(Landmark landmark,
                                                             bool has_intermediate_traffic_light) {
  switch (landmark) {
    case Landmark::kEndOfRoad:
      return Translate("at the end of the road", "{landmark}");
    case Landmark::kAtTrafficLight:
      return has_intermediate_traffic_light ? Translate("at the second traffic light", "{landmark}")
                                            : Translate("at the traffic light", "{landmark}");
    case Landmark::kOnToBridge:
    case Landmark::kOnBridge:
    case Landmark::kAfterBridge:
    case Landmark::kIntoTunnel:
    case Landmark::kInsideTunnel:
    case Landmark::kAfterTunnel:
      break;
  }
  TT_LOG_WARNING(kLogId, "Unsupported landmark: {}", static_cast<int>(landmark));
  return {"", locale_, Translated::kYes};
}

void InstructionTextProvider::SetLocale(const std::string& locale) {
  TT_LOG_INFO(kLogId, "SetLocale: {}", locale);
  locale_ = locale;
  LazyInitCatalog();
}

void InstructionTextProvider::SetUnitSystem(distance_rounding::UnitSystem unit_system) {
  TT_LOG_INFO(kLogId, "SetUnitSystem: {}", unit_system);
  unit_system_ = unit_system;
}

void InstructionTextProvider::SetRoundingSpecification(
    distance_rounding::RoundingSpecification rounding_specification) {
  TT_LOG_INFO(kLogId, "SetRoundingSpecification: {}", rounding_specification);
  rounding_specification_ = rounding_specification;
}

}  // namespace internal
}  // namespace text_generation
}  // namespace navkit2
}  // namespace tomtom
