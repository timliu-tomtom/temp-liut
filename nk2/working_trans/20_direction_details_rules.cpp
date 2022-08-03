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
using TurnDirection = TurnDirection;
}  // namespace

std::vector<Rule> InstructionRulesFactory::GetDirectionDetailsRules() const {
  return {

        Rule{{
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               Not<HasTowardName>(),
           },
           Translate(  //
               "onto {road_number}", "exit_highway")},

            Rule{{
               InstructionTypeIs(Type::kExit),
               //Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasTowardName(),
               IsVerbosityLevel(VerbosityLevel::kCompact),
           },
           Translate(  //
               "toward {toward_name}")},
      Rule{{
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               //Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasTowardName(),
           },
           Translate(  //
               "onto {road_number} toward {toward_name}", "exit_highway")},


      Rule{{
               InstructionTypeIs(Type::kTurn),
               TurnDirectionIs{TurnDirection::kSlightRight, TurnDirection::kRight,
                               TurnDirection::kSharpRight, TurnDirection::kSlightLeft,
                               TurnDirection::kLeft, TurnDirection::kSharpLeft},
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasTowardName(),
           },
           Translate(  //
               "onto {road_number} toward {toward_name}", "turn_left_right")},
      Rule{{
               InstructionTypeIs(Type::kTurn),
               TurnDirectionIs{TurnDirection::kStraight},
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasTowardName(),
           },
           Translate(  //
               "onto {road_number} toward {toward_name}", "turn_go_straight")},
      Rule{{
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
               HasTowardName(),
           },
           Translate(  //
               "onto {road_number} toward {toward_name}")},
               /*
      Rule{{
               InstructionTypeIs(Type::kExit),
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
           },
           Translate(  //
               "onto {road_number}", "exit_highway")},
               */
      Rule{{
               InstructionTypeIs(Type::kTurn),
               TurnDirectionIs{TurnDirection::kSlightRight, TurnDirection::kRight,
                               TurnDirection::kSharpRight, TurnDirection::kSlightLeft,
                               TurnDirection::kLeft, TurnDirection::kSharpLeft},
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
           },
           Translate(  //
               "onto {road_number}", "turn_left_right")},
      Rule{{
               InstructionTypeIs(Type::kTurn),
               TurnDirectionIs{TurnDirection::kStraight},
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
           },
           Translate(  //
               "onto {road_number}", "turn_go_straight")},
      Rule{{
               HasRoadNumber(),
               Or<Not<HasStreetName>, Not<IsUrbanArea>>(),
           },
           Translate(  //
               "onto {road_number}")},

      Rule{{
               HasStreetName(),
               HasIntoPhonetics(),
               HasTowardName(),
           },
           Translate(  //
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case} toward "
               "{toward_name}")},
      Rule{{
               HasStreetName(),
               HasIntoPhonetics(),
           },
           Translate(  //
               "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case}")},

      Rule{{
               InstructionTypeIs(Type::kTurn),
               TurnDirectionIs{TurnDirection::kStraight},
               HasStreetName(),
               HasTowardName(),
           },
           Translate(  //
               "onto {road_name} toward {toward_name}", "turn_go_straight")},
      Rule{{
               HasStreetName(),
               HasTowardName(),
           },
           Translate(  //
               "onto {road_name} toward {toward_name}")},
      Rule{{
               InstructionTypeIs(Type::kTurn),
               TurnDirectionIs{TurnDirection::kStraight},
               HasStreetName(),
           },
           Translate(  //
               "onto {road_name}", "turn_go_straight")},
      Rule{{
               HasStreetName(),
           },
           Translate(  //
               "onto {road_name}")},

      Rule{{
               HasTowardName(),
           },
           Translate(  //
               "toward {toward_name}")},

      // fallback if no direction_details for the message
      Rule{{},
           Translate(  //
               "")},
  };
}

}  // namespace internal
}  // namespace text_generation
}  // namespace navkit2
}  // namespace tomtom