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

#ifndef NAVIGATION_TEXT_GENERATION_SRC_TRANSLATED_MESSAGE_HPP
#define NAVIGATION_TEXT_GENERATION_SRC_TRANSLATED_MESSAGE_HPP

#include <string>

namespace tomtom {
namespace navkit2 {
namespace text_generation {
namespace internal {

enum class Translated { kNo, kYes };

/**
 * Structure containing translated message text and translation locale.
 */
struct TranslatedMessage {
  TranslatedMessage() = default;
    TranslatedMessage(std::string text_arg, std::string locale_arg, Translated is_translated_arg)
      : text(std::move(text_arg)),
        locale(std::move(locale_arg)),
        is_translated(is_translated_arg),
        in_english(""),
        ctx("") {}
  TranslatedMessage(std::string text_arg, std::string locale_arg, Translated is_translated_arg, std::string in_english_arg)
      : text(std::move(text_arg)),
        locale(std::move(locale_arg)),
        is_translated(is_translated_arg),
        in_english(in_english_arg),
        ctx("") {}

  TranslatedMessage(std::string text_arg, std::string locale_arg, Translated is_translated_arg, std::string in_english_arg, std::string ctx_arg)
      : text(std::move(text_arg)),
        locale(std::move(locale_arg)),
        is_translated(is_translated_arg),
        in_english(in_english_arg),
        ctx(ctx_arg) {}

  bool operator==(const TranslatedMessage& other) const {
    return text == other.text && locale == other.locale && is_translated == other.is_translated;
  }
  bool operator!=(const TranslatedMessage& other) const {
    return !operator==(other);
  }

  std::string text;
  std::string locale;
  Translated is_translated = Translated::kNo;  //! indicates if text is translated
  std::string in_english;
  std::string ctx;
};

}  // namespace internal
}  // namespace text_generation
}  // namespace navkit2
}  // namespace tomtom

#endif  // NAVIGATION_TEXT_GENERATION_SRC_TRANSLATED_MESSAGE_HPP
