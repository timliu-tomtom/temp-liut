/*
 * Copyright (C) 2022 TomTom NV. All rights reserved.
 *
 * This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
 * used for internal evaluation purposes or commercial use strictly subject to separate
 * license agreement between you and TomTom NV. If you are the licensee, you are only permitted
 * to use this software in accordance with the terms of your license agreement. If you are
 * not the licensee, you are not authorized to use this software in any manner and should
 * immediately return or destroy it.
 */

#include <vector>

#include "instruction_rule_factory.hpp"

namespace tomtom {
namespace navkit2 {
namespace text_generation {
namespace internal {

namespace {
using Rule = InstructionRulesFactory::Rule;
using Type = AudioInstructionType;
using DrivingSide = DrivingSide;
using CombinedMessagePart = internal::CombinedMessagePart;
using CombinedMessageType = InstructionTextProviderInterface::CombinedMessagePart;
}  // namespace

std::vector<Rule> InstructionRulesFactory::GetExitLeftRules() const {
  return {
      // Exit - kLeft
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasRoadNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left {direction_details}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasRoadNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasRoadNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left onto {road_number} toward "
               "{toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasRoadNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left onto {road_number} toward "
               "{toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               HasRoadNumber(),
               HasTowardName(),
               HasExitName(),
           },
           Translate(  //
               "In {distance} take the left exit {direction_details}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               HasRoadNumber(),
               HasTowardName(),
               HasExitName(),
           },
           Translate(  //
               "In {distance} take the left exit onto {road_number} toward {toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit onto {road_number} toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               HasExitNumber(),
               HasExitName(),
               HasIntersectionName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left at {intersection_name} "
               "toward {toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               HasExitNumber(),
               HasIntersectionName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left at {intersection_name} "
               "toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasIntersectionName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left at {intersection_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasIntersectionName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left at {intersection_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left onto {road_number}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left onto {road_number}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasStreetName(),
               HasTowardName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left "
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case} toward "
               "{toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasStreetName(),
               HasTowardName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left "
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case} toward "
               "{toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasStreetName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left "
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasStreetName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left "
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasTowardName(),
               HasStreetName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left onto {road_name} toward "
               "{toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasTowardName(),
               HasStreetName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left onto {road_name} toward "
               "{toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasStreetName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left onto {road_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasStreetName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left onto {road_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               HasIntersectionName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit at {intersection_name} toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasIntersectionName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit at {intersection_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasExitName(),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit {direction_details}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               HasExitName(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit onto {road_number}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit onto {road_number}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitName(),
               HasTowardName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit {road_name_preposition_and_article_for_into_case} "
               "{road_name_for_into_case} toward {toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasTowardName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit {road_name_preposition_and_article_for_into_case} "
               "{road_name_for_into_case} toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit {road_name_preposition_and_article_for_into_case} "
               "{road_name_for_into_case}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit {road_name_preposition_and_article_for_into_case} "
               "{road_name_for_into_case}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit onto {road_name} toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kWarning, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "In {distance} take the left exit onto {road_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasExitName(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "Take the exit {exit_number} on the left toward {toward_name}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "Take the exit {exit_number} on the left toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "Take the exit {exit_number} on the left.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "Take the exit {exit_number} on the left.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "Take the left exit {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "Take the left exit toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasExitName(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left {direction_details}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasExitName(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left toward {toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasExitName(),
               HasSignpost(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the left exit {direction_details}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the left exit {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasTowardName(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the left exit toward {toward_name}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the left exit toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               IsVerbosityLevel(VerbosityLevel::kCompact),
               HasExitName(),
           },
           Translate(  //
               "In {distance} take the left exit.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "In {distance} take the left exit.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasExitName(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left {direction_details}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasExitName(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left toward {toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the exit {exit_number} on the left.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasTowardName(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the left exit {direction_details}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the left exit {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasTowardName(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the left exit toward {toward_name}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasSignpost(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the left exit toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the left exit.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kFarAway, MessageType::kMain, MessageType::kWarning),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "In {distance} take the left exit.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasRoadNumber(),
               HasTowardName(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasRoadNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasRoadNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasRoadNumber(),
               HasTowardName(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_number} toward {toward_name}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasRoadNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_number} toward {toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasRoadNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_number} toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntersectionName(),
               HasExitNumber(),
               HasTowardName(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left at {intersection_name} toward "
               "{toward_name}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntersectionName(),
               HasExitNumber(),
               HasExitName(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left at {intersection_name} toward "
               "{toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntersectionName(),
               HasTowardName(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left at {intersection_name} toward "
               "{toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntersectionName(),
               HasExitNumber(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left at {intersection_name}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntersectionName(),
               HasExitNumber(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left at {intersection_name}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntersectionName(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left at {intersection_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasExitName(),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasExitNumber(),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               HasExitNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_number}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               HasExitNumber(),
               HasExitName(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_number}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               HasExitNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_number}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               HasIntoPhonetics(),
               HasTowardName(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left "
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case} toward "
               "{toward_name}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               HasExitName(),
               HasIntoPhonetics(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left "
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case} toward "
               "{toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               HasIntoPhonetics(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left "
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case} toward "
               "{toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               HasIntoPhonetics(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left "
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               HasExitName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left "
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left "
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               HasTowardName(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_name} toward {toward_name}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               HasExitName(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_name} toward {toward_name}.",
               "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasTowardName(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_name} toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_name}.", "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_name}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the exit {exit_number} on the left onto {road_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit {direction_details}.", "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit onto {road_number} toward {toward_name}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit onto {road_number} toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntersectionName(),
               HasTowardName(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit at {intersection_name} toward {toward_name}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               HasIntersectionName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit at {intersection_name} toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntersectionName(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit at {intersection_name}.", "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntersectionName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit at {intersection_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit {direction_details}.", "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit onto {road_number}.", "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit onto {road_number}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasTowardName(),
               HasIntoPhonetics(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit {road_name_preposition_and_article_for_into_case} "
               "{road_name_for_into_case} toward {toward_name}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasTowardName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit {road_name_preposition_and_article_for_into_case} "
               "{road_name_for_into_case} toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasIntoPhonetics(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit {road_name_preposition_and_article_for_into_case} "
               "{road_name_for_into_case}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasIntoPhonetics(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit {road_name_preposition_and_article_for_into_case} "
               "{road_name_for_into_case}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               HasStreetName(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit onto {road_name} toward {toward_name}.", "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               HasStreetName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit onto {road_name} toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               HasIntermediateSideStreet(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit onto {road_name}.", "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasStreetName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit onto {road_name}.")},
      Rule{{
               InstructionTypeIs(Type::kExit),
               CombinedMessagePart(CombinedMessageType::kSecond),
               HasIntermediateSideStreet(),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasExitNumber(),
           },
           Translate(  //
               "Then take the exit {exit_number} on the left.", "second_freeway_exit")},
      Rule{{
               InstructionTypeIs(Type::kExit),
               CombinedMessagePart(CombinedMessageType::kSecond),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasExitNumber(),
               HasExitName(),
           },
           Translate(  //
               "Then take the exit {exit_number} on the left.", "has_exit_name")},
      Rule{{
               InstructionTypeIs(Type::kExit),
               CombinedMessagePart(CombinedMessageType::kSecond),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasExitNumber(),
           },
           Translate(  //
               "Then take the exit {exit_number} on the left.")},
      Rule{{
               InstructionTypeIs(Type::kExit),
               CombinedMessagePart(CombinedMessageType::kSecond),
               HasIntermediateSideStreet(),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Then take the left exit.", "second_freeway_exit")},
      Rule{{
               InstructionTypeIs(Type::kExit),
               CombinedMessagePart(CombinedMessageType::kSecond),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Then take the left exit.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntermediateSideStreet(),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasTowardName(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasExitNumber(),
               HasTowardName(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasExitNumber(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the exit {exit_number} on the left {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntermediateSideStreet(),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasTowardName(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the exit {exit_number} on the left toward {toward_name}.",
               "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasTowardName(),
               HasExitNumber(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the exit {exit_number} on the left toward {toward_name}.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasTowardName(),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the exit {exit_number} on the left toward {toward_name}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntermediateSideStreet(),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the exit {exit_number} on the left.", "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasExitNumber(),
               HasExitName(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the exit {exit_number} on the left.", "has_exit_name")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               HasExitNumber(),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the exit {exit_number} on the left.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntermediateSideStreet(),
               HasTowardName(),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the left exit {direction_details}.", "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the left exit {direction_details}.")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasIntermediateSideStreet(),
               HasTowardName(),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the left exit toward {toward_name}.", "second_freeway_exit")},
      Rule{{
               MessageTypeIs(MessageType::kExtendedConfirmation),
               InstructionTypeIs(Type::kExit),
               HasTowardName(),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
               IsVerbosityLevel(VerbosityLevel::kComprehensive),
           },
           Translate(  //
               "Take the left exit toward {toward_name}.")},
      Rule{{
               InstructionTypeIs(Type::kExit),
               HasIntermediateSideStreet(),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit.", "second_freeway_exit")},
      Rule{{
               InstructionTypeIs(Type::kExit),
               ExitDirectionIs(ExitDirection::kLeft),
               IsDrivingSide(DrivingSide::kRight),
           },
           Translate(  //
               "Take the left exit.")},
  };
}

}  // namespace internal
}  // namespace text_generation
}  // namespace navkit2
}  // namespace tomtom
