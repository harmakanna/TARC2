Common_EventScript_MoveOutsideNPCsInside::
    setflag FLAG_HIDE_OUTSIDE_NPCS
    clearflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
    return
    
Common_EventScript_MoveInsideNPCsOutside::
    clearflag FLAG_HIDE_OUTSIDE_NPCS
    setflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
    setflag FLAG_HIDE_TORNADUS_NPCS
    return

InsideOutside_EventScript_GentlemanInside::
    setvar VAR_TEMP_1, LOCALID_INSIDE_GENTLEMAN
    goto InsideOutside_EventScript_Gentleman
    end

InsideOutside_EventScript_GentlemanOutside::
    setvar VAR_TEMP_1, LOCALID_OUTSIDE_GENTLEMAN
    goto InsideOutside_EventScript_Gentleman
    end

InsideOutside_EventScript_AngryManInside::
    setvar VAR_TEMP_1, LOCALID_INSIDE_ANGRY_MAN
    goto InsideOutside_EventScript_AngryMan
    end

InsideOutside_EventScript_AngryManOutside::
    setvar VAR_TEMP_1, LOCALID_OUTSIDE_ANGRY_MAN
    goto InsideOutside_EventScript_AngryMan
    end

InsideOutside_EventScript_LeafInside::
    setvar VAR_TEMP_1, LOCALID_INSIDE_LEAF
    goto InsideOutside_EventScript_Leaf
    end

InsideOutside_EventScript_LeafOutside::
    setvar VAR_TEMP_1, LOCALID_OUTSIDE_LEAF
    goto InsideOutside_EventScript_Leaf
    end
    
InsideOutside_EventScript_YoungsterOutside::
    setvar VAR_TEMP_1, LOCALID_OUTSIDE_YOUNGSTER
    goto InsideOutside_EventScript_Youngster
    end

InsideOutside_EventScript_YoungsterInside::
    setvar VAR_TEMP_1, LOCALID_INSIDE_YOUNGSTER
    goto InsideOutside_EventScript_Youngster
    end

InsideOutside_EventScript_AceTrainerOutside::
    setvar VAR_TEMP_1, LOCALID_OUTSIDE_ACE_TRAINER
    goto InsideOutside_EventScript_AceTrainer
    end

InsideOutside_EventScript_AceTrainerInside::
    setvar VAR_TEMP_1, LOCALID_INSIDE_ACE_TRAINER
    goto InsideOutside_EventScript_AceTrainer
    end

InsideOutside_EventScript_Gentleman::
    lock
    faceplayer
    call Script_GetNPCFacingDirection
    speak VAR_TEMP_1, VAR_0x8005, Name_Gentleman, InsideOutside_Text_GentlemanNiceHavingMoney
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIndeedItIs
    speak VAR_TEMP_1, VAR_0x8005, Name_Gentleman, InsideOutside_Text_GentlemanIndeed
    closemessage
    applymovement VAR_TEMP_1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

InsideOutside_EventScript_AngryMan::
    lock
    faceplayer
    goto_if_set FLAG_SPOKE_TO_ANGRY_MAN_POST_AQUACORP, InsideOutside_EventScript_CalmMan
    call Script_GetNPCFacingDirection
    speak VAR_TEMP_1, VAR_0x8005, Name_Angry_Man, InsideOutside_Text_AngryManAngry
    checkspecies SPECIES_GOREBYSS
    goto_if_eq VAR_RESULT, TRUE, InsideOutside_EventScript_AngryManActually
    checkspecies SPECIES_HUNTAIL
    goto_if_eq VAR_RESULT, TRUE, InsideOutside_EventScript_AngryManActually
    returnqueststate QUEST_INTERROGATE_MATT
    goto_if_eq VAR_RESULT, 4, InsideOutside_EventScript_LookerDots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerTroubling
    closemessage
    release
    end

InsideOutside_EventScript_LookerDots::
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Dots
    closemessage
    release
    end

InsideOutside_EventScript_AngryManActually::
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerActuallyChowder
    closemessage
    playse SE_PIN
    applymovement VAR_TEMP_1, Common_Movement_ExclamationMark
    waitmovement 0
    delay 50
    speak VAR_TEMP_1, VAR_0x8005, Name_Angry_Man, InsideOutside_Text_AngryManReally
    closemessage
    setflag FLAG_SPOKE_TO_ANGRY_MAN_POST_AQUACORP
    release
    end
    
InsideOutside_EventScript_CalmMan::
    speakername Name_Calm_Man
    msgbox InsideOutside_Text_AngryManCuteName, MSGBOX_DEFAULT
    closemessage
    release
    end
    
InsideOutside_EventScript_Leaf::
	lock
	call Script_GetNPCFacingDirection
	goto_if_unset FLAG_SYS_MAIN_GAME_START, InsideOutside_EventScript_LeafPreGame
	returnqueststate QUEST_FIND_THE_CULPRIT
    switch VAR_RESULT
	case 1, InsideOutside_EventScript_LeafPreQuest
	case 2, InsideOutside_EventScript_LeafQuest
	case 4, InsideOutside_EventScript_LeafPostQuest
	release
    end

InsideOutside_EventScript_LeafPreGame::
    faceplayer
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerWouldYouKnow
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerAlrightCarryOn
    closemessage
    applymovement VAR_TEMP_1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

InsideOutside_EventScript_LeafPreQuest::
    faceplayer
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerWouldYouKnowLandorus
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerColdShoulder
    closemessage
    applymovement VAR_TEMP_1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

InsideOutside_EventScript_LeafQuest::
    subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FIND_THE_CULPRIT, SUB_QUEST_DEFEAT_LEAF
    goto_if_eq VAR_RESULT, TRUE, InsideOutside_EventScript_LeafPostQuest
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_YouAreUnderSuspicion
    call_if_eq VAR_FACING, DIR_NORTH, InsideOutside_EventScript_TargetTurnFaceLookerNorth
    call_if_eq VAR_FACING, DIR_WEST, InsideOutside_EventScript_TargetTurnFaceLookerWest
    call_if_eq VAR_FACING, DIR_SOUTH, InsideOutside_EventScript_TargetTurnFaceLookerSouth
    call_if_eq VAR_FACING, DIR_EAST, InsideOutside_EventScript_TargetTurnFaceLookerEast
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, InsideOutside_Text_LeafQuestionMark
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnowYouDidIt
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, InsideOutside_Text_LeafExclamationMark
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ComingWithMe
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    goto_if_eq VAR_CHOOSE_CULPRIT, 2, InsideOutside_EventScript_LeafCulpritQuest
    setflag FLAG_SYS_NO_WHITEOUT
    trainerbattle_no_intro TRAINER_LEAF, Looker_Text_Dots
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_LOST, InsideOutside_EventScript_LeafDefeat
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, SUB_QUEST_DEFEAT_LEAF
	clearflag FLAG_SYS_NO_WHITEOUT
	goto InsideOutside_EventScript_LeafPostQuest
    release
    end

InsideOutside_EventScript_LeafCulpritQuest::
    setflag FLAG_SYS_NO_WHITEOUT
    trainerbattle_no_intro TRAINER_LEAF_CULPRIT, Looker_Text_Dots
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_LOST, InsideOutside_EventScript_LeafDefeat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnewItWasYou
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerSoWhyDidYouDoIt
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, InsideOutside_Text_LeafSad
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIGuessItDoesntMatter
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, SUB_QUEST_DEFEAT_LEAF
	questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT
	clearflag FLAG_SYS_NO_WHITEOUT
    release
    end

InsideOutside_EventScript_LeafDefeat::
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIllBeBack
    closemessage
    applymovement VAR_TEMP_1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    clearflag FLAG_SYS_NO_WHITEOUT
    release
    end

InsideOutside_EventScript_LeafPostQuest::
	goto_if_eq VAR_CHOOSE_CULPRIT, 2, InsideOutside_EventScript_LeafCulpritPostQuest
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerSorryForBotheringYou
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerOkayThen
    closemessage
    applymovement VAR_TEMP_1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

InsideOutside_EventScript_LeafCulpritPostQuest::
    faceplayer
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIHope
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerOkayThen
    closemessage
    applymovement VAR_TEMP_1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

InsideOutside_EventScript_TargetTurnFaceLookerNorth::
    playse SE_PIN
    applymovement VAR_TEMP_1, Common_Movement_FaceDownQuestionMark
    waitmovement 0
    delay 50
    return

InsideOutside_EventScript_TargetTurnFaceLookerWest::
    playse SE_PIN
    applymovement VAR_TEMP_1, Common_Movement_FaceRightQuestionMark
    waitmovement 0
    delay 50
    return

InsideOutside_EventScript_TargetTurnFaceLookerSouth::
    playse SE_PIN
    applymovement VAR_TEMP_1, Common_Movement_FaceUpQuestionMark
    waitmovement 0
    delay 50
    return

InsideOutside_EventScript_TargetTurnFaceLookerEast::
    playse SE_PIN
    applymovement VAR_TEMP_1, Common_Movement_FaceLeftQuestionMark
    waitmovement 0
    delay 50
    return

InsideOutside_EventScript_Youngster::
	lock
	call Script_GetNPCFacingDirection
	goto_if_unset FLAG_SYS_MAIN_GAME_START, InsideOutside_EventScript_YoungsterPreGame
	returnqueststate QUEST_FIND_THE_CULPRIT
    switch VAR_RESULT
	case 1, InsideOutside_EventScript_YoungsterPreQuest
	case 2, InsideOutside_EventScript_YoungsterQuest
	case 4, InsideOutside_EventScript_YoungsterPostQuest
	release
    end

InsideOutside_EventScript_YoungsterPreGame::
    faceplayer
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerToYoungsterPregame
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterPregame
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIConcur
    closemessage
    release
    end

InsideOutside_EventScript_YoungsterPreQuest::
    faceplayer
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerToYoungsterPrequest
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterPrequest
    returnqueststate QUEST_INTERROGATE_MATT
    goto_if_eq VAR_RESULT, 4, InsideOutside_EventScript_LookerDots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIConcur
    closemessage
    release
    end

InsideOutside_EventScript_YoungsterQuest::
    subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FIND_THE_CULPRIT, SUB_QUEST_DEFEAT_YOUNGSTER
    goto_if_eq VAR_RESULT, TRUE, InsideOutside_EventScript_YoungsterPostQuest
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_YouAreUnderSuspicion
    call_if_eq VAR_FACING, DIR_NORTH, InsideOutside_EventScript_TargetTurnFaceLookerNorth
    call_if_eq VAR_FACING, DIR_WEST, InsideOutside_EventScript_TargetTurnFaceLookerWest
    call_if_eq VAR_FACING, DIR_SOUTH, InsideOutside_EventScript_TargetTurnFaceLookerSouth
    call_if_eq VAR_FACING, DIR_EAST, InsideOutside_EventScript_TargetTurnFaceLookerEast
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterHuh
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnowYouDidIt
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterWrongPerson
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ComingWithMe
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterSomebodyHelp
    goto_if_eq VAR_CHOOSE_CULPRIT, 4, InsideOutside_EventScript_YoungsterCulpritQuest
    setflag FLAG_SYS_NO_WHITEOUT
    trainerbattle_no_intro TRAINER_YOUNGSTER, InsideOutside_Text_YoungsterAhh
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_LOST, InsideOutside_EventScript_YoungsterDefeat
    subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, SUB_QUEST_DEFEAT_YOUNGSTER
    clearflag FLAG_SYS_NO_WHITEOUT
    goto InsideOutside_EventScript_YoungsterPostQuest
    release
    end

InsideOutside_EventScript_YoungsterCulpritQuest::
    setflag FLAG_SYS_NO_WHITEOUT
    trainerbattle_no_intro TRAINER_YOUNGSTER_CULPRIT, InsideOutside_Text_YoungsterAhh
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_LOST, InsideOutside_EventScript_YoungsterDefeat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnewItWasYou
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterImSorry
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerAhaStatus
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterOkay
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerComeWithMe
    closemessage
    subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, SUB_QUEST_DEFEAT_YOUNGSTER
    questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT
    clearflag FLAG_SYS_NO_WHITEOUT
    release
    end

InsideOutside_EventScript_YoungsterDefeat::
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterWierdo
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerNotOffTheHook
    closemessage
    clearflag FLAG_SYS_NO_WHITEOUT
    release
    end

InsideOutside_EventScript_YoungsterPostQuest::
    goto_if_eq InsideOutside_EventScript_YoungsterCulpritPostQuest
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterAhh
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerOffTheHook
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterGetAwayFromMe
    closemessage
    release
    end
    
InsideOutside_EventScript_YoungsterCulpritPostQuest::
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterImSorryPostQuest
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerNoWorries
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterUhh
    closemessage
    release
    end

InsideOutside_EventScript_AceTrainer::
    release
    end

InsideOutside_Text_YoungsterImSorryPostQuest:
    .string "I'm sorry, sir…\p"
    .string "I won't try to catch legendary Pokémon\n"
    .string "any more…$"

InsideOutside_Text_LookerNoWorries:
    .string "Not a problem, young man!\p"
    .string "Remember, material possession will never\n"
    .string "truly satisfy your psychological needs!$"
    
InsideOutside_Text_YoungsterUhh:
    .string "Uhh… okay?$"

InsideOutside_Text_YoungsterImSorry:
    .string "Waaaaah! I'm sorry, sir!\p"
    .string "I didn't know catching Landorus would throw\n"
    .string "the weather out of whack!\p"
    .string "I just wanted to show my friends at home how\n"
    .string "cool I was by catching something really\l"
    .string "strong…$"

InsideOutside_Text_LookerAhaStatus:
    .string "Aha! So you wanted Landorus as a status\n"
    .string "symbol to boost your ego!\p"
    .string "Well, I remember how much that mattered\n"
    .string "in my younger years…\p"
    .string "So long as you release Landorus back into\n"
    .string "the wild, I am willing to overlook your\l"
    .string "small transgression!$"

InsideOutside_Text_YoungsterOkay:
    .string "Okay, sir…$"

InsideOutside_Text_LookerComeWithMe:
    .string "Wonderful!\n"
    .string "Come with me, young lad!$"

InsideOutside_Text_YoungsterHuh:
    .string "Wait, huh?\p"
    .string "Gee sir, I think you have the wrong guy!\p"
    .string "Isn't that Pokémon supposed to be really\n"
    .string "powerful?\p"
    .string "I can't catch something like that!$"
    
InsideOutside_Text_YoungsterWrongPerson:
    .string "What the heck!?\p"
    .string "Shut up, I didn't do anything bad!$"

InsideOutside_Text_YoungsterSomebodyHelp:
    .string "Aaaaaaaah! Get away from me!\n"
    .string "Somebody, help!$"

InsideOutside_Text_YoungsterAhh:
    .string "Aaaahhhhhh!$"

InsideOutside_Text_YoungsterWierdo:
    .string "Get away from me, you freak!$"

InsideOutside_Text_LookerNotOffTheHook:
    .string "You're not off the hook yet, young\n"
    .string "man! I will be back!$"

InsideOutside_Text_LookerOffTheHook:
    .string "Huh.\p"
    .string "I suppose you did not catch Landorus.\p"
    .string "You're off the hook then! My apologies for\n"
    .string "the accusation.$"

InsideOutside_Text_YoungsterGetAwayFromMe:
    .string "Get away from me!$"

InsideOutside_Text_LookerToYoungsterPrequest:
    .string "Hello, young lad!\p"
    .string "I am investigating the cause of a\n"
    .string "particular Pokémon's disappearance, a\l"
    .string "Landorus, from the local forest!\p"
    .string "Tell me, would you happen to have any\n"
    .string "information on the matter?$"

InsideOutside_Text_YoungsterPrequest:
    .string "No can do, sir! I haven't been here\n"
    .string "very long!\p"
    .string "If anything, I bet it's those evil Team\n"
    .string "Aqua thugs messing with the wildlife\l"
    .string "again!\p"
    .string "They're never up to any good!$"
    
InsideOutside_Text_LookerToYoungsterPregame:
    .string "Hello, citizen!\p"
    .string "I am investigating Team Aqua for any\n"
    .string "suspicious activity they may or may\l"
    .string "not be partaking in!\p"
    .string "Tell me, would you happen to have any\n"
    .string "information on the matter?$"

InsideOutside_Text_YoungsterPregame:
    .string "Sorry, sir! I only just arrived here\n"
    .string "the other day!\p"
    .string "I didn't know Team Aqua set up here, I\n"
    .string "don't trust them one bit!$"

InsideOutside_Text_LookerIConcur:
    .string "I concur! Young lad, we are of the same\n"
    .string "mind on this!$"

InsideOutside_Text_LookerSoWhyDidYouDoIt:
    .string "So! Why did you do it?\p"
    .string "What compelled you to capture Landorus\n"
    .string "and throw the city into chaos?$"

InsideOutside_Text_LookerIGuessItDoesntMatter:
    .string "…I guess it doesn't matter why!\p"
    .string "Hmm… I would be willing to overlook your\n"
    .string "transgression if you come with me and\l"
    .string "release Landorus back into the forest!$"

InsideOutside_Text_LookerIllTakeThatAsAYes:
    .string "… … …\n"
    .string "I'll take that as a yes! Come with me.$"

InsideOutside_Text_LookerSorryForBotheringYou:
    .string "Uhh… I guess you are cleared of suspicion!\n"
    .string "My apologies for bothering you.\p"
    .string "Would you happen to have any information I\n"
    .string "could use to find the culprit?$"

InsideOutside_Text_LookerIHope:
    .string "I hope you've learned your lesson! Be sure\n"
    .string "not to get into any more trouble!$"

InsideOutside_Text_LookerOkayThen:
    .string "Okay then…$"

InsideOutside_Text_LookerIllBeBack:
    .string "Hmm… You make a good point…\p"
    .string "I'm not done investigating you, though…\p"
    .string "I'll be back!$"

InsideOutside_Text_LeafQuestionMark:
    .string "…?$"

InsideOutside_Text_LeafExclamationMark:
    .string "…!$"

InsideOutside_Text_LeafSad:
    .string "… :($"

InsideOutside_Text_LookerWouldYouKnow:
	.string "Hello, citizen!\p"
	.string "I believe there is something evil afoot\n"
	.string "regarding Team Aqua!\p"
	.string "Young lady, would you happen to know if\n"
	.string "they have been causing trouble?$"

InsideOutside_Text_LookerWouldYouKnowLandorus:
    .string "Hello, young lady!\p"
    .string "I am on the prowl to discover what\n"
    .string "exactly happened to Landorus!\p"
    .string "Tell me, do you have any information\n"
    .string "on the case of the missing legend?$"

InsideOutside_Text_LookerColdShoulder:
    .string "…Giving the cold shoulder, huh!\p"
    .string "Okay then, I can ask somebody else!$"

InsideOutside_Text_LookerAlrightCarryOn:
    .string "…Okay then! Carry on!$"

InsideOutside_Text_GentlemanNiceHavingMoney:
    .string "Oh ho ho!\p"
    .string "Isn't it wonderful being an adult?\p"
    .string "Unlike those silly children, we have\n"
    .string "the money to heal our Pokémon\l"
    .string "whenever we want!\p"
    .string "Sir, don't you think that's nice?$"

InsideOutside_Text_LookerIndeedItIs:
    .string "Indeed it is.$"

InsideOutside_Text_GentlemanIndeed:
    .string "Oh ho ho!\n"
    .string "Indeed!$"

InsideOutside_Text_AngryManAngry:
    .string "This is outrageous!\p"
    .string "Team Aqua is menacing our wildlife!\p"
    .string "Have you heard? They're turning the\n"
    .string "local Clamperl into Clamperl Chowder!\p"
    .string "How despicable!$"

InsideOutside_Text_LookerTroubling:
    .string "That is rather troubling…$"

InsideOutside_Text_LookerActuallyChowder:
    .string "Actually, Chowder was the name of\n"
    .string "one of the Clamperl they studied.\p"
    .string "They figured out how to evolve the\n"
    .string "Pokémon in captivity.\p"
    .string "In fact, he's with me now.$"

InsideOutside_Text_AngryManReally:
    .string "Really?\p"
    .string "The Clamperl Chowder was actually\n"
    .string "the Clamperl, Chowder?\p"
    .string "Well I'll be…$"

InsideOutside_Text_AngryManCuteName:
    .string "You know…\p"
    .string "Chowder's kind of a cute name…$"
