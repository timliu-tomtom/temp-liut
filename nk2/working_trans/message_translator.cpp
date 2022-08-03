/*
 * Copyright (C) 2021 TomTom NV. All rights reserved.
 *
 * This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
 * used for internal evaluation purposes or commercial use strictly subject to separate
 * license agreement between you and TomTom NV. If you are the licensee, you are only permitted
 * to use this software in accordance with the terms of your license agreement. If you are
 * not the licensee, you are not authorized to use this software in any manner and should
 * immediately return or destroy it.
 */

#include "message_translator.hpp"

#include <memory>

#include <spirit_po/spirit_po.hpp>

#include <tomtom/navkit2/log.hpp>

namespace {
constexpr auto kLogId = "navigation-text-generation";
}

namespace tomtom {
namespace navkit2 {
namespace text_generation {
namespace internal {

const std::string kDefaultLocale = "en-US";

class MessageTranslator::MessageTranslatorImpl final {
 public:
  MessageTranslatorImpl(const std::unordered_map<std::string, std::string>& lang_translation_map,
                        const std::string& locale_as_arg)
      : locale(locale_as_arg),
        catalog(CreateCatalogForLanguage(lang_translation_map, locale_as_arg)) {}

  MessageTranslatorImpl() : locale(kDefaultLocale){};
  std::unique_ptr<spirit_po::default_catalog> CreateCatalogForLanguage(
      const std::unordered_map<std::string, std::string>& lang_translation_map,
      const std::string& locale_as_arg) {
    const auto it = lang_translation_map.find(locale_as_arg);
    if (it == lang_translation_map.end()) {
      return {};
    }
    return std::make_unique<spirit_po::default_catalog>(
        spirit_po::default_catalog::from_range(it->second));
  }

  std::string locale;
  std::unique_ptr<spirit_po::default_catalog> catalog;
};

MessageTranslator::MessageTranslator() : impl_(std::make_shared<MessageTranslatorImpl>()) {}

MessageTranslator::MessageTranslator(
    const std::unordered_map<std::string, std::string>& lang_translation_map,
    const std::string& locale)
    : impl_(std::make_shared<MessageTranslatorImpl>(lang_translation_map, locale)) {
  // since SPIRIT_PO_NO_EXCEPTIONS is defined, an object of spirit_po::catalog should be created
  if (*impl_->catalog) {
    TT_LOG_INFO(kLogId, "Localization string is parsed.");
  } else {
    TT_LOG_WARNING(kLogId,
                   "Localization string for locale {} cannot be opened due to the error: {}",
                   impl_->locale, impl_->catalog->error());
  }
}

TranslatedMessage MessageTranslator::Translate(const std::string& message_in_english) const {
  if (impl_->catalog && *impl_->catalog &&
      impl_->catalog->gettext_line_no(message_in_english) > 0) {
    return {impl_->catalog->gettext_str(message_in_english), impl_->locale,
            internal::Translated::kYes, message_in_english};
  }

  return {message_in_english, kDefaultLocale, internal::Translated::kNo};
}

TranslatedMessage MessageTranslator::Translate(const std::string& message_in_english,
                                               const std::string& context) const {
  if (impl_->catalog && *impl_->catalog &&
      impl_->catalog->pgettext_line_no(context, message_in_english) > 0) {
    return {impl_->catalog->pgettext_str(context, message_in_english), impl_->locale,
            internal::Translated::kYes, message_in_english, context};
  }

  return {message_in_english, kDefaultLocale, internal::Translated::kNo};
}

TranslatedMessage MessageTranslator::Translate(const std::string& message_in_english_in_singular,
                                               const std::string& message_in_english_in_plural,
                                               long count) const {
  if (impl_->catalog && *impl_->catalog &&
      impl_->catalog->gettext_line_no(message_in_english_in_singular) > 0) {
    const std::string translated_message =
        impl_->catalog->ngettext_str(message_in_english_in_singular, message_in_english_in_plural,
                                     static_cast<unsigned int>(count));
    return {translated_message, impl_->locale, internal::Translated::kYes};
  }

  std::string message_in_english =
      (count == 1 ? message_in_english_in_singular : message_in_english_in_plural);
  return {std::move(message_in_english), kDefaultLocale, internal::Translated::kNo};
}

TranslatedMessage MessageTranslator::Translate(const std::string& message_in_english_in_singular,
                                               const std::string& message_in_english_in_plural,
                                               const std::string& context, long count) const {
  if (impl_->catalog && *impl_->catalog &&
      impl_->catalog->pgettext_line_no(context, message_in_english_in_singular) > 0) {
    std::string translated_message = impl_->catalog->npgettext_str(
        context, message_in_english_in_singular, message_in_english_in_plural,
        static_cast<unsigned int>(count));
    return {std::move(translated_message), impl_->locale, internal::Translated::kYes};
  }

  std::string message_in_english =
      (count == 1 ? message_in_english_in_singular : message_in_english_in_plural);
  return {std::move(message_in_english), kDefaultLocale, internal::Translated::kNo};
}

}  // namespace internal
}  // namespace text_generation
}  // namespace navkit2
}  // namespace tomtom
