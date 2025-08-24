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
    goto_if_eq VAR_CUTSCENE_STATE, 4, InsideOutside_EventScript_GentlemanSaveTheChild
    speak VAR_TEMP_1, VAR_0x8005, Name_Gentleman, InsideOutside_Text_GentlemanNiceHavingMoney
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIndeedItIs
    speak VAR_TEMP_1, VAR_0x8005, Name_Gentleman, InsideOutside_Text_GentlemanIndeed
    closemessage
    applymovement VAR_TEMP_1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

InsideOutside_EventScript_GentlemanSaveTheChild::
    speak VAR_TEMP_1, VAR_0x8005, Name_Gentleman, InsideOutside_Text_GentlemanLostChild
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_WillDo
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
    subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FIND_THE_CULPRIT, 2
    goto_if_eq VAR_RESULT, TRUE, InsideOutside_EventScript_LeafPostQuest
    setflag FLAG_SYS_DISAPPEAR_QUESTS
    playbgm MUS_PL_LOOKER, TRUE
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
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InsideOutside_EventScript_LeafDefeat
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, 2
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
	clearflag FLAG_SYS_NO_WHITEOUT
    fadedefaultbgm
	goto InsideOutside_EventScript_LeafPostQuest
    release
    end

InsideOutside_EventScript_LeafCulpritQuest::
    setflag FLAG_SYS_NO_WHITEOUT
    trainerbattle_no_intro TRAINER_LEAF_CULPRIT, Looker_Text_Dots
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_LOST, InsideOutside_EventScript_LeafDefeat
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InsideOutside_EventScript_LeafDefeat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnewItWasYou
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerSoWhyDidYouDoIt
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, InsideOutside_Text_LeafSad
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIGuessItDoesntMatter
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    closemessage
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, 2
	questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
	clearflag FLAG_SYS_NO_WHITEOUT
    clearflag FLAG_HIDE_SHRINE_LEAF
    clearflag FLAG_HIDE_SHRINE_PROSPERITY_PRESENT_ANABEL
    setflag FLAG_SYS_PREVENT_MAP_FADE
    setvar VAR_CUTSCENE_STATE, 14
    warp MAP_SHRINE_OF_PROSPERITY_PRESENT, 12, 16
    waitstate
    release
    end

InsideOutside_EventScript_LeafDefeat::
    speak VAR_TEMP_1, VAR_0x8005, Name_Leaf, Looker_Text_Dots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIllBeBack
    closemessage
    fadedefaultbgm
    applymovement VAR_TEMP_1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
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
    goto_if_eq VAR_CUTSCENE_STATE, 4, InsideOutside_EventScript_YoungsterLostChild
	goto_if_unset FLAG_SYS_MAIN_GAME_START, InsideOutside_EventScript_YoungsterPreGame
	returnqueststate QUEST_FIND_THE_CULPRIT
    switch VAR_RESULT
	case 1, InsideOutside_EventScript_YoungsterPreQuest
	case 2, InsideOutside_EventScript_YoungsterQuest
	case 4, InsideOutside_EventScript_YoungsterPostQuest
	release
    end

InsideOutside_EventScript_YoungsterLostChild::
    faceplayer
    speakername Name_Youngster
    msgbox InsideOutside_Text_YoungsterThisStorm, MSGBOX_DEFAULT
    closemessage
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
    subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FIND_THE_CULPRIT, 4
    goto_if_eq VAR_RESULT, TRUE, InsideOutside_EventScript_YoungsterPostQuest
    setflag FLAG_SYS_DISAPPEAR_QUESTS
    playbgm MUS_PL_LOOKER, TRUE
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
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InsideOutside_EventScript_YoungsterDefeat
    subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, 4
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
    clearflag FLAG_SYS_NO_WHITEOUT
    fadedefaultbgm
    goto InsideOutside_EventScript_YoungsterPostQuest
    release
    end

InsideOutside_EventScript_YoungsterCulpritQuest::
    setflag FLAG_SYS_NO_WHITEOUT
    trainerbattle_no_intro TRAINER_YOUNGSTER_CULPRIT, InsideOutside_Text_YoungsterAhh
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_LOST, InsideOutside_EventScript_YoungsterDefeat
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InsideOutside_EventScript_YoungsterDefeat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnewItWasYou
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterImSorry
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerAhaStatus
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterOkay
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerComeWithMe
    closemessage
    subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, 4
    questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT
    clearflag FLAG_SYS_NO_WHITEOUT
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
    clearflag FLAG_HIDE_SHRINE_YOUNGSTER
    clearflag FLAG_HIDE_SHRINE_PROSPERITY_PRESENT_ANABEL
    setflag FLAG_SYS_PREVENT_MAP_FADE
    setvar VAR_CUTSCENE_STATE, 14    
    warp MAP_SHRINE_OF_PROSPERITY_PRESENT, 12, 16
	waitstate
    release
    end

InsideOutside_EventScript_YoungsterDefeat::
    speak VAR_TEMP_1, VAR_0x8005, Name_Youngster, InsideOutside_Text_YoungsterWierdo
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerNotOffTheHook
    closemessage
    fadedefaultbgm
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
    clearflag FLAG_SYS_NO_WHITEOUT
    release
    end

InsideOutside_EventScript_YoungsterPostQuest::
    goto_if_eq VAR_CHOOSE_CULPRIT, 3, InsideOutside_EventScript_YoungsterCulpritPostQuest
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
    lock
	call Script_GetNPCFacingDirection
    goto_if_eq VAR_CUTSCENE_STATE, 4, InsideOutside_EventScript_AceTrainerLostChild
	goto_if_unset FLAG_SYS_MAIN_GAME_START, InsideOutside_EventScript_AceTrainerPreGame
	returnqueststate QUEST_FIND_THE_CULPRIT
    switch VAR_RESULT
	case 1, InsideOutside_EventScript_AceTrainerPreQuest
	case 2, InsideOutside_EventScript_AceTrainerQuest
	case 4, InsideOutside_EventScript_AceTrainerPostQuest
    release
    end

InsideOutside_EventScript_AceTrainerLostChild::
    faceplayer
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerLostChild
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Dots
    closemessage
    release
    end

InsideOutside_EventScript_AceTrainerPreGame::
    faceplayer
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerToAceTrainerPregame
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerPregame
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerISee
    closemessage
    release
    end

InsideOutside_EventScript_AceTrainerPreQuest::
    faceplayer
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerToAceTrainerPrequest
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerPrequest
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerPleaseReport
    closemessage
    release
    end

InsideOutside_EventScript_AceTrainerQuest::
    subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FIND_THE_CULPRIT, 3
    goto_if_eq VAR_RESULT, TRUE, InsideOutside_EventScript_AceTrainerPostQuest
    setflag FLAG_SYS_DISAPPEAR_QUESTS
    playbgm MUS_PL_LOOKER, TRUE
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_YouAreUnderSuspicion
    call_if_eq VAR_FACING, DIR_NORTH, InsideOutside_EventScript_TargetTurnFaceLookerNorth
    call_if_eq VAR_FACING, DIR_WEST, InsideOutside_EventScript_TargetTurnFaceLookerWest
    call_if_eq VAR_FACING, DIR_SOUTH, InsideOutside_EventScript_TargetTurnFaceLookerSouth
    call_if_eq VAR_FACING, DIR_EAST, InsideOutside_EventScript_TargetTurnFaceLookerEast
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerImSorryWhat
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnowYouDidIt
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerOhBrother
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ComingWithMe
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerLetsJustBattle
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_UhhOkay
    goto_if_eq VAR_CHOOSE_CULPRIT, 3, InsideOutside_EventScript_AceTrainerCulpritQuest
    setflag FLAG_SYS_NO_WHITEOUT
    trainerbattle_no_intro TRAINER_BW_ACE_TRAINER, InsideOutside_Text_AceTrainerDefeated
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_LOST, InsideOutside_EventScript_AceTrainerDefeat
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InsideOutside_EventScript_AceTrainerDefeat
    subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, 3
    clearflag FLAG_SYS_NO_WHITEOUT
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
    fadedefaultbgm
    goto InsideOutside_EventScript_AceTrainerPostQuest
    release
    end

InsideOutside_EventScript_AceTrainerCulpritQuest::
    setflag FLAG_SYS_NO_WHITEOUT
    trainerbattle_no_intro TRAINER_BW_ACE_TRAINER_CULPRIT, InsideOutside_Text_AceTrainerCulpritDefeated
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_LOST, InsideOutside_EventScript_AceTrainerDefeat
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InsideOutside_EventScript_AceTrainerDefeat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnewItWasYou
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerYouGotLucky
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerUmUhh
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerWhatever
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerThatSoundsSystemic
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerLetsGetItOverWith
    closemessage
    subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, 3
    questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT
    clearflag FLAG_SYS_NO_WHITEOUT
    clearflag FLAG_HIDE_SHRINE_ACE_TRAINER
    clearflag FLAG_HIDE_SHRINE_PROSPERITY_PRESENT_ANABEL
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
    setflag FLAG_SYS_PREVENT_MAP_FADE
    setvar VAR_CUTSCENE_STATE, 14
    warp MAP_SHRINE_OF_PROSPERITY_PRESENT, 12, 16
	waitstate
    release
    end

InsideOutside_EventScript_AceTrainerDefeat::
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerSigh
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerUhhIllBeBack
    closemessage
    fadedefaultbgm
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
    clearflag FLAG_SYS_NO_WHITEOUT
    release
    end

InsideOutside_EventScript_AceTrainerPostQuest::
    goto_if_eq VAR_CHOOSE_CULPRIT, 3, InsideOutside_EventScript_AceTrainerCulpritPostQuest
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerThere
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerOh
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerThanksForWastingMyTime
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIThink
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerCoolBye
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Dots
    closemessage
    release
    end

InsideOutside_EventScript_AceTrainerCulpritPostQuest::
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerThereCulprit
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerIHopeYouLearnedYourLesson
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerDontYouHaveSomeoneElse
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Uhh
    speak VAR_TEMP_1, VAR_0x8005, Name_Ace_Trainer, InsideOutside_Text_AceTrainerCoolBye
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Dots
    closemessage
    release
    end

InsideOutside_Text_YoungsterThisStorm:
    .string "Gee, this storm came out of nowhere!\p"
    .string "I thought it was gonna be perfect\n"
    .string "weather for the next two weeks!\p"
    .string "What a bummer…$"
    
InsideOutside_Text_AceTrainerLostChild:
    .string "Wow, a child got lost in the forest?\p"
    .string "Skill issue.$"

InsideOutside_Text_AceTrainerThereCulprit:
    .string "There, you got me…\p"
    .string "Gonna harass me some more?$"

InsideOutside_Text_LookerIHopeYouLearnedYourLesson:
    .string "I hope you learned your lesson, young\n"
    .string "lady! Do not mess with nature!$"

InsideOutside_Text_AceTrainerDontYouHaveSomeoneElse:
    .string "Whatever. Don't you have someone\n"
    .string "else to annoy?$"

InsideOutside_Text_AceTrainerThere:
    .string "There, you got me…\p"
    .string "Oh wait! No you didn't. I didn't\n"
    .string "catch Landorus, Einstein!$"

InsideOutside_Text_LookerOh:
    .string "Oh. Well…\p"
    .string "Thank you for your cooperation in\n"
    .string "this investigation?$"

InsideOutside_Text_AceTrainerThanksForWastingMyTime:
    .string "Thank YOU for wasting my time!\n"
    .string "Don't you have someone else to annoy?$"

InsideOutside_Text_LookerIThink:
    .string "…I think…?$"

InsideOutside_Text_AceTrainerCoolBye:
    .string "Cool!\p"
    .string "Bye!$"

InsideOutside_Text_AceTrainerSigh:
    .string "Sigh… You're an officer of the law\n"
    .string "but you can't even beat a teenager…?\p"
    .string "Wow…$"

InsideOutside_Text_LookerUhhIllBeBack:
    .string "Uhh…\p"
    .string "Well…\p"
    .string "I will be back!$"

InsideOutside_Text_AceTrainerYouGotLucky:
    .string "No, you didn't, and no, it's not…\p"
    .string "You guessed it was me and got lucky…$"

InsideOutside_Text_LookerUmUhh:
    .string "Um… Uhh…\n"
    .string "It's…\l"
    .string "All in the name of safety?$"

InsideOutside_Text_AceTrainerWhatever:
    .string "Whatever… I was just trying to fill\n"
    .string "out my Pokédex for Professor Juniper…$"

InsideOutside_Text_LookerThatSoundsSystemic:
    .string "So you caught Landorus for a Pokédex\n"
    .string "entry?\p"
    .string "I guess that IS common practice for aspiring\n"
    .string "trainers…\p"
    .string "… … …Anyways!\n"
    .string "That's an issue for our government to solve!\p"
    .string "So long as you release Landorus, I can\n"
    .string "let this minor transgression go.$"

InsideOutside_Text_GentlemanLostChild:
    .string "Ohohoho!\p"
    .string "I heard the commotion about the lost\n"
    .string "child.\p"
    .string "Good man, stay safe out there!$"

InsideOutside_Text_AceTrainerLetsGetItOverWith:
    .string "Sure, let's just get this over with…$"

InsideOutside_Text_AceTrainerDefeated:
    .string "Sigh… Are you happy now…?$"

InsideOutside_Text_AceTrainerCulpritDefeated:
    .string "Sigh… You got me…$"

InsideOutside_Text_AceTrainerImSorryWhat:
    .string "I'm sorry…\n"
    .string "What?$"

InsideOutside_Text_AceTrainerOhBrother:
    .string "Oh brother, you're one of THOSE kinds of\n"
    .string "investigators, huh…\p"
    .string "Can you like… explain why you think it's\n"
    .string "me…?$"

InsideOutside_Text_AceTrainerLetsJustBattle:
    .string "Man…\p"
    .string "Let's just setting this with a battle…\n"
    .string "It'll save both of us time…$"

InsideOutside_Text_LookerToAceTrainerPrequest:
    .string "Good afternoon, young lady!\p"
    .string "I am investigating the disappearance\n"
    .string "of a local legend, Landorus!\p"
    .string "Would you happen to have any leads on\n"
    .string "its whereabouts?$"

InsideOutside_Text_AceTrainerPrequest:
    .string "I've got nothing.$"

InsideOutside_Text_LookerPleaseReport:
    .string "Oh, okay.\p"
    .string "Well…\p"
    .string "Please report any suspicious activity\n"
    .string "you may notice to City Hall!$"

InsideOutside_Text_LookerToAceTrainerPregame:
    .string "Good afternoon.\p"
	.string "My name…\n"
	.string "Is Looker!\p"
    .string "I am on the prowl for any information\n"
    .string "regarding Team Aqua's recent activity\l"
    .string "in Porta Bella!\p"
    .string "Would you be able to help me in my\n"
    .string "pursuit of knowledge?$"

InsideOutside_Text_AceTrainerPregame:
    .string "No.$"

InsideOutside_Text_LookerISee:
    .string "I see.\p"
    .string "Well, if you learn anything about Team\n"
    .string "Aqua, please report that information\l"
    .string "to City Hall!\p"
    .string "It is imperative they do not disrupt the\n"
    .string "peace of the region again!$"

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
    .string "I didn't know catching Landorus would\n"
    .string "throw the weather out of whack!\p"
    .string "I just wanted to show my friends at\n"
    .string "home how cool I was by catching a\l"
    .string "really strong Pokémon…$"

InsideOutside_Text_LookerAhaStatus:
    .string "Aha! So you wanted Landorus as a status\n"
    .string "symbol to boost your ego!\p"
    .string "Well, I remember how much that mattered\n"
    .string "in my younger years…\p"
    .string "So long as you release Landorus back\n"
    .string "into the wild, I am willing to overlook\l"
    .string "your small transgression!$"

InsideOutside_Text_YoungsterOkay:
    .string "Okay, sir…$"

InsideOutside_Text_LookerComeWithMe:
    .string "Wonderful!\n"
    .string "Come with me, young lad!$"

InsideOutside_Text_YoungsterHuh:
    .string "Wait, huh?\p"
    .string "Gee sir, I think you have the wrong guy!\p"
    .string "Isn't that Pokémon supposed to be\n"
    .string "really powerful?\p"
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
    .string "You're off the hook then! My apologies\n"
    .string "for the accusation.$"

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
    .string "Uhh…\n"
    .string "I guess you are cleared of suspicion!\p"
    .string "My apologies for bothering you.\p"
    .string "Would you happen to have any info I\n"
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
	.string "Hello, citizen.\p"
	.string "My name…\n"
	.string "Is Looker.\p"
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
