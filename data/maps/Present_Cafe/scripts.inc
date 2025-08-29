Present_Cafe_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PresentCafe_OnTransition
	.byte 0

PresentCafe_OnTransition:
	call_if_set FLAG_SWEET_TOOTH_WENT_CRAZY, PresentCafe_EventScript_PlaceCook
	end

PresentCafe_EventScript_PlaceCook::
	setobjectxyperm LOCALID_CAFE_COOK, 9, 5
	setobjectmovementtype LOCALID_CAFE_COOK, MOVEMENT_TYPE_FACE_RIGHT
	return

Present_Cafe_EventScript_Emma::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_Cafe_EventScript_EmmaPreGame
	returnqueststate QUEST_BONJOUR_EMMA
	goto_if_eq VAR_RESULT, 4, Present_Cafe_EventScript_EmmaPostQuest
	call Script_GetNPCFacingDirection
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaBonjour
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerBonjour
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaComoCaVa
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerWhatDoISayHere, MSGBOX_DEFAULT
	multichoice 0, 3, MULTI_SPEAK_WITH_EMMA_1, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaDontKnowFrench_1_1
	goto_if_eq VAR_RESULT, 2, Present_Cafe_EventScript_EmmaLeaveYouAlone
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerBienMerci
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaTresBien
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerWhatDoISayHere, MSGBOX_DEFAULT
	multichoice 0, 3, MULTI_SPEAK_WITH_EMMA_2, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaDontKnowFrench_2_1
	goto_if_eq VAR_RESULT, 1, Present_Cafe_EventScript_EmmaDontKnowFrench_2_2
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerJeMappelle
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaEnchantee
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerHuh, MSGBOX_DEFAULT
	multichoice 0, 3, MULTI_SPEAK_WITH_EMMA_3, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaDontKnowFrench_3_1
	goto_if_eq VAR_RESULT, 1, Present_Cafe_EventScript_EmmaSad
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerJePeux
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaMerciBeaucoup
	multichoice 0, 6, MULTI_EMMA_GIVEMON, TRUE
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaGiveGumshoos
	goto_if_eq VAR_RESULT, 1, Present_Cafe_EventScript_EmmaGiveMeowstic
	release
	end

Present_Cafe_EventScript_EmmaPreGame::
	msgbox Present_Cafe_Text_EmmaCoffeeDelicious, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaPostQuest::
	faceplayer
	goto_if_unset FLAG_HIDE_PRESENT_LUVDISCS, Present_Cafe_EventScript_EmmaLovesLuvdiscs
	speakername Name_Emma
	msgbox Present_Cafe_Text_EmmaPostQuest, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaLovesLuvdiscs::
	speakername Name_Emma
	msgbox Present_Cafe_Text_EmmaLovesLuvdiscs, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_1_1::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerOui
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaLeaveYouAlone::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerMal
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaLeaveYouAlone
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_2_1::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerMonNom
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_2_2::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerJeSuisLooker
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_3_1::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerSure
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaSad::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerNoThanks
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaAhDaccord
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaWrongAnswer::
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerWrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaFinishQuest::
	completequest QUEST_BONJOUR_EMMA
	release
	end

Present_Cafe_EventScript_SweetTooth::
	lock
	goto_if_unset FLAG_TALKED_TO_PRESENT_SWEET_TOOTH, Present_Cafe_EventScript_SweetToothThankYou
	speak LOCALID_PRESENT_SWEET_TOOTH, DIR_WEST, Name_Sweet_Tooth, Present_Cafe_Text_SweetToothOneRareCandy
	speak LOCALID_CAFE_COOK, DIR_EAST, Name_Cook, Present_Cafe_Text_CookSoMany
	closemessage
	special SpawnCameraObject
	fadenewbgm MUS_NONE
	call_if_eq VAR_FACING, DIR_WEST, Present_Cafe_EventScript_PanCameraLeft
	call_if_eq VAR_FACING, DIR_NORTH, Present_Cafe_EventScript_PanCameraUp
	delay 90
	speak LOCALID_PRESENT_SWEET_TOOTH, DIR_WEST, Name_Sweet_Tooth, Present_Cafe_Text_SweetToothOoo
	speak LOCALID_CAFE_COOK, DIR_EAST, Name_Cook, Present_Cafe_Text_CookGivesIn
	playbgm MUS_DP_SUNYSHORE_DAY, TRUE
	speak LOCALID_PRESENT_SWEET_TOOTH, DIR_WEST, Name_Sweet_Tooth, Present_Cafe_Text_SweetToothYay
	call_if_eq VAR_FACING, DIR_WEST, Present_Cafe_EventScript_PanCameraRight
	call_if_eq VAR_FACING, DIR_NORTH, Present_Cafe_EventScript_PanCameraDown
	special RemoveCameraObject
	closemessage
	release
	end

Present_Cafe_EventScript_PanCameraUp::
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	waitmovement 0
	return

Present_Cafe_EventScript_PanCameraDown::
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	waitmovement 0
	return
	
Present_Cafe_EventScript_PanCameraLeft::
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft
	waitmovement 0
	return
	
Present_Cafe_EventScript_PanCameraRight::
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight
	waitmovement 0
	return

Present_Cafe_EventScript_SweetToothThankYou::
	faceplayer
	playse SE_PIN
	applymovement LOCALID_PRESENT_SWEET_TOOTH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 50
	call Script_GetNPCFacingDirection
	speak LOCALID_PRESENT_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Present_Cafe_Text_SweetToothThankYou
	speakername NULL
	giveitem ITEM_LIFE_ORB, 1
	closemessage
	applymovement LOCALID_PRESENT_SWEET_TOOTH, Common_Movement_FaceLeft
	waitmovement 0
	setflag FLAG_TALKED_TO_PRESENT_SWEET_TOOTH
	release
	end

Present_Cafe_EventScript_Cook::
	lock
	faceplayer
	speakername Name_Cook
	msgbox Present_Cafe_Text_Cook, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAFE_COOK, Common_Movement_FaceRight
	waitmovement
	release
	end

Present_Cafe_EventScript_May::
	lock
	call Script_GetNPCFacingDirection
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_Cafe_EventScript_MayPreGame
	returnqueststate QUEST_FIND_THE_CULPRIT
	switch VAR_RESULT
	case 1, Present_Cafe_EventScript_MayPreQuest
	case 2, Present_Cafe_EventScript_MayQuest
	case 4, Present_Cafe_EventScript_MayPostQuest
	release
	end

Present_Cafe_EventScript_MayPreGame::
	faceplayer
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerHelloMay
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayPregame
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerAhYes
	closemessage
	applymovement LOCALID_CAFE_MAY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end 

Present_Cafe_EventScript_MayPreQuest::
	faceplayer
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerHelloMayPreQuest
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayPrequest
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerWonderful
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayUhhSure
	closemessage
	applymovement LOCALID_CAFE_MAY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_MayQuest::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FIND_THE_CULPRIT, 1
	goto_if_eq VAR_RESULT, TRUE, Present_Cafe_EventScript_MayPostQuest
    setflag FLAG_SYS_DISAPPEAR_QUESTS
    playbgm MUS_PL_LOOKER, TRUE
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_YouAreUnderSuspicion
	setvar VAR_TEMP_1, LOCALID_CAFE_MAY
    call_if_eq VAR_FACING, DIR_NORTH, InsideOutside_EventScript_TargetTurnFaceLookerNorth
    call_if_eq VAR_FACING, DIR_WEST, InsideOutside_EventScript_TargetTurnFaceLookerWest
    call_if_eq VAR_FACING, DIR_SOUTH, InsideOutside_EventScript_TargetTurnFaceLookerSouth
    call_if_eq VAR_FACING, DIR_EAST, InsideOutside_EventScript_TargetTurnFaceLookerEast
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayHuh
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnowYouDidIt
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayImJustConfused
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ComingWithMe
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayWhatOkay
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerISuppose
	goto_if_eq VAR_CHOOSE_CULPRIT, 1, Present_Cafe_EventScript_MayCulpritQuest
	setflag FLAG_SYS_NO_WHITEOUT
	trainerbattle_no_intro TRAINER_MAY, Present_Cafe_Text_MayDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Present_Cafe_EventScript_MayDefeat
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, Present_Cafe_EventScript_MayDefeat
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, 1
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
	clearflag FLAG_SYS_NO_WHITEOUT
	fadedefaultbgm
	goto Present_Cafe_EventScript_MayPostQuest
	release
	end

Present_Cafe_EventScript_MayCulpritQuest::
	setflag FLAG_SYS_NO_WHITEOUT
	trainerbattle_no_intro TRAINER_MAY_CULPRIT, Present_Cafe_Text_MayDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Present_Cafe_EventScript_MayDefeat
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, Present_Cafe_EventScript_MayDefeat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerIGuessThatWasFaster
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayIKnowRight
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerYouSeemResponsible
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayWellIDidntKnow
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerSensible
	closemessage
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, 1
	questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_HIDE_SHRINE_MAY
    clearflag FLAG_HIDE_SHRINE_PROSPERITY_PRESENT_ANABEL
    setflag FLAG_SYS_PREVENT_MAP_FADE
	setvar VAR_CUTSCENE_STATE, 14
    warp MAP_SHRINE_OF_PROSPERITY_PRESENT, 12, 16
	waitstate
	release
	end

Present_Cafe_EventScript_MayDefeat::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerCityHallWouldHaveBeenFaster
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayIGuessSo
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerSurelyAnotherBattle
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MaySure
	closemessage
	clearflag FLAG_SYS_NO_WHITEOUT
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
	fadedefaultbgm
	applymovement LOCALID_CAFE_MAY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_MayPostQuest::
	goto_if_eq VAR_CHOOSE_CULPRIT, 1, Present_Cafe_EventScript_MayCulpritPostQuest
	faceplayer
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerIGuessThatWasFaster
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayIKnowRight
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerThankYouForYourCooperation
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayNoProblem
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerOfCourse
	closemessage
	applymovement LOCALID_CAFE_MAY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
Present_Cafe_EventScript_MayCulpritPostQuest::
	faceplayer
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerAllsWellThatEndsWell
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayAgreed
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerIndeedTheyShould
	speak LOCALID_CAFE_MAY, VAR_0x8005, Name_May, Present_Cafe_Text_MayBummer
	closemessage
	applymovement LOCALID_CAFE_MAY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_Barista::
	lock
	call_if_eq VAR_FACING, DIR_WEST, Present_Cafe_EventScript_TurnBaristaEast
	call_if_eq VAR_FACING, DIR_NORTH, Present_Cafe_EventScript_TurnBaristaSouth
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_Cafe_EventScript_BaristaPreGame
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_GET_INTO_THE_GROOVE
	switch VAR_RESULT
	case 1, Present_Cafe_EventScript_BaristaPreQuest
	case 2, Present_Cafe_EventScript_BaristaQuest
	case 3, Present_Cafe_EventScript_BaristaReward
	case 4, Present_Cafe_EventScript_BaristaPostQuest
	release 
	end

Present_Cafe_EventScript_BaristaPreGame::
	msgbox Present_Cafe_Text_BaristaPreGame, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Present_Cafe_EventScript_BaristaPreQuest::
	speak LOCALID_CAFE_BARISTA, VAR_0x8005, Name_Barista, Present_Cafe_Text_BaristaNervous
	speakername NULL
	msgbox Present_Cafe_Text_BaristaSweating, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_YouDontLookVeryGood
	speak LOCALID_CAFE_BARISTA, VAR_0x8005, Name_Barista, Present_Cafe_Text_BaristaIsCooked
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IWillHandleThis
	speak LOCALID_CAFE_BARISTA, VAR_0x8005, Name_Barista, Present_Cafe_Text_BaristaLifesaver
	startquest QUEST_GET_INTO_THE_GROOVE
	release
	end
	
Present_Cafe_EventScript_BaristaQuest::
	speak LOCALID_CAFE_BARISTA, VAR_0x8005, Name_Barista, Present_Cafe_Text_BaristaIsCookedShort
	closemessage
	release
	end

Present_Cafe_EventScript_BaristaReward::
	speak LOCALID_CAFE_BARISTA, VAR_0x8005, Name_Barista, Present_Cafe_Text_BaristaYouDidIt
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_AlwaysHappyToHelp
	speak LOCALID_CAFE_BARISTA, VAR_0x8005, Name_Barista, Present_Cafe_Text_BaristaImBroke
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerThatSoundsWonderful
	completequest QUEST_GET_INTO_THE_GROOVE
	release
	end

Present_Cafe_EventScript_BaristaPostQuest::
	speak LOCALID_CAFE_BARISTA, VAR_0x8005, Name_Barista, Present_Cafe_Text_BaristaPostQuest
	speakername NULL
	msgbox Present_Cafe_Text_WouldYouLikeADrink, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Present_Cafe_EventScript_BaristaDidntChangeAbility
	msgbox Present_Cafe_Text_WhichPokemonAbility, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Present_Cafe_EventScript_BaristaDidntChangeAbility
	special SwitchMonAbility
	msgbox Present_Cafe_Text_LookerFeelingRefreshed, MSGBOX_DEFAULT
	speak LOCALID_CAFE_BARISTA, VAR_0x8005, Name_Barista, Present_Cafe_Text_BaristaHaveAGoodOne
	closemessage
	release
	end

Present_Cafe_EventScript_BaristaDidntChangeAbility::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_NoThanks
	call Script_GetNPCFacingDirection
	speak LOCALID_CAFE_BARISTA, VAR_0x8005, Name_Barista, Present_Cafe_Text_BaristaNoProblemo
	closemessage
	release
	end

Present_Cafe_EventScript_TurnBaristaEast::
	applymovement LOCALID_CAFE_BARISTA, Common_Movement_FaceRight
	waitmovement 0
	setobjectmovementtype LOCALID_CAFE_BARISTA, MOVEMENT_TYPE_FACE_RIGHT
	return

Present_Cafe_EventScript_TurnBaristaSouth::
	applymovement LOCALID_CAFE_BARISTA, Common_Movement_FaceDown
	waitmovement 0
	setobjectmovementtype LOCALID_CAFE_BARISTA, MOVEMENT_TYPE_FACE_DOWN
	return

Present_Cafe_EventScript_LeftIdol::
	lock
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_GET_INTO_THE_GROOVE
	goto_if_eq VAR_RESULT, 3, Present_Cafe_EventScript_LeftIdolPrereqReward
	goto_if_ne VAR_RESULT, 4, Present_Cafe_EventScript_LeftIdolPrereqQuest
	release
	end

Present_Cafe_EventScript_LeftIdolPrereqReward::
	speak LOCALID_CAFE_LEFT_IDOL, VAR_0x8005, Name_Left_Idol, Present_Cafe_Text_LeftIdolPrereqReward
	closemessage
	applymovement LOCALID_CAFE_LEFT_IDOL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_LeftIdolPrereqQuest::
	speak LOCALID_CAFE_LEFT_IDOL, VAR_0x8005, Name_Right_Idol, Present_Cafe_Text_LeftWorried
	closemessage
	applymovement LOCALID_CAFE_LEFT_IDOL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_RightIdol::
	lock
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_GET_INTO_THE_GROOVE
	goto_if_eq VAR_RESULT, 3, Present_Cafe_EventScript_RightIdolPrereqReward
	goto_if_ne VAR_RESULT, 4, Present_Cafe_EventScript_RightIdolPrereqQuest
	release
	end

Present_Cafe_EventScript_RightIdolPrereqReward::
	speak LOCALID_CAFE_RIGHT_IDOL, VAR_0x8005, Name_Right_Idol, Present_Cafe_Text_RightIdolPrereqReward
	closemessage
	applymovement LOCALID_CAFE_RIGHT_IDOL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_RightIdolPrereqQuest::
	goto_if_set FLAG_HIDE_CAFE_IDOL_LISIA, Present_Cafe_EventScript_RightWorriedLisia
	speak LOCALID_CAFE_RIGHT_IDOL, VAR_0x8005, Name_Right_Idol, Present_Cafe_Text_RightWorriedLeft
	closemessage
	applymovement LOCALID_CAFE_RIGHT_IDOL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_RightWorriedLisia::
	speak LOCALID_CAFE_RIGHT_IDOL, VAR_0x8005, Name_Right_Idol, Present_Cafe_Text_RightWorriedLisia
	closemessage
	applymovement LOCALID_CAFE_RIGHT_IDOL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_Lisia::
	lockall
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_GET_INTO_THE_GROOVE
	goto_if_eq VAR_RESULT, 3, Present_Cafe_EventScript_LisiaPrereqReward
	goto_if_ne VAR_RESULT, 4, Present_Cafe_EventScript_LisiaPrereqQuest
	returnqueststate QUEST_BREAK_A_LEG
	@ switch VAR_RESULT
	@ case 1, Present_Cafe_EventScript_LisiaGiveQuest
	@ case 2, Present_Cafe_EventScript_LisiaQuest
	@ case 4, Present_Cafe_EventScript_LisiaPostQuest
	releaseall
	end

Present_Cafe_EventScript_LisiaPrereqReward::
	speakername Name_Lisia
	msgbox Present_Cafe_Text_LisiaPrereqReward, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAFE_LEFT_IDOL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Present_Cafe_EventScript_LisiaPrereqQuest::
	goto_if_set FLAG_HIDE_CAFE_IDOL_RIGHT, Present_Cafe_EventScript_LisiaWorriedRight
	speak LOCALID_CAFE_LISIA, VAR_0x8005, Name_Lisia, Present_Cafe_Text_LisiaWorriedLeft
	closemessage
	applymovement LOCALID_CAFE_LISIA, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Present_Cafe_EventScript_LisiaWorriedRight::
	speak LOCALID_CAFE_LISIA, VAR_0x8005, Name_Lisia, Present_Cafe_Text_LisiaWorriedRight
	closemessage
	applymovement LOCALID_CAFE_LISIA, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Present_Cafe_Text_BaristaNervous:
	.string "Uhh, welcome to the Torin Tauros\n"
	.string "Tourin' Café, home to Moomoo Bella's\l"
	.string "famous Moomoo Bell!$"

Present_Cafe_Text_BaristaSweating:
	.string "The man is sweating profusely.$"

Present_Cafe_Text_BaristaIsCooked:
	.string "Dude, I'm so cooked!\p"
	.string "My boss paid a FORTUNE for these pop-\n"
	.string "stars to come out and put on a show!\p"
	.string "If they aren't here by 5 PM tonight,\n"
	.string "he's 100 percent totally gonna blame me\l"
	.string "and dock my pay!\p"
	.string "Where even are they? Did they get lost\n"
	.string "in the storm or something?\p"
	.string "Oh, please help me find them, dude…$"

Present_Cafe_Text_BaristaLifesaver:
	.string "Yo, you would?\p"
	.string "You're a lifesaver!\p"
	.string "They're a group of three. I'm sure if\n"
	.string "you look around enough, they should pop\l"
	.string "up somewhere. They gotta!$"

Present_Cafe_Text_BaristaIsCookedShort:
	.string "I'm so cooked…\n"
	.string "I'm so cooked…\p"
	.string "Please help me…$"

Present_Cafe_Text_BaristaYouDidIt:
	.string "MY MAN!!!!\p"
	.string "They're all here and accounted for!\n"
	.string "A few hours early too!\p"
	.string "Is Looker your name?\n"
	.string "I cannot thank you enough, dude.$"
	
Present_Cafe_Text_BaristaImBroke:
	.string "Look, I'm pretty uhh…\p"
	.string "Broke.\p"
	.string "I don't have much I can give as a\n"
	.string "reward, buuuuuuuut I can brew up a\l"
	.string "banger coffee for you, any time!\p"
	.string "I can add in these gnarly spices I\n"
	.string "find in the forest here and there!\p"
	.string "Get this, for some reason they change\n"
	.string "a Pokémon's ability!\p"
	.string "Won't do anything to 'em if they only\n"
	.string "got one ability though!\p"
	.string "It's on the house, my treat!$"

Present_Cafe_Text_LookerThatSoundsWonderful:
	.string "That sounds wonderful, sir.\n"
	.string "The gesture is truly appreciated.$"

Present_Cafe_Text_WhichPokemonAbility:
	.string "Which Pokémon will switch their\n"
	.string "ability?$"

Present_Cafe_Text_BaristaPreGame:
	.string "Welcome to the Tourin' Torin\n"
	.string "Tauros Café, home to Porta Bella's\l"
	.string "famous Moomoo Milk!$"

Present_Cafe_Text_BaristaPostQuest:
	.string "Welcome back to the Tauros Cafe,\n"
	.string "Looker!\p"
	.string "Any time you want a free coffee, let\n"
	.string "me know!$"

Present_Cafe_Text_WouldYouLikeADrink:
	.string "Would you like a freshly brewed,\n"
	.string "ability-switching coffee?$"

Present_Cafe_Text_LookerFeelingRefreshed:
	.string "Looker and {STR_VAR_1} are feeling\n"
	.string "quite relaxed!$"

Present_Cafe_Text_BaristaNoProblemo:
	.string "No problemo, my dude!\n"
	.string "Have a good one!$"

Present_Cafe_Text_BaristaHaveAGoodOne:
	.string "Hope that coffee rocked your body!\n"
	.string "Have a good one, my dude!$"

Present_Cafe_Text_LookerThankYouForYourCooperation:
	.string "Anyways, thank you for your\n"
	.string "cooperation, young miss!\p"
	.string "I appreciate when suspects are not\n"
	.string "jumpy and confrontational…$"

Present_Cafe_Text_MayNoProblem:
	.string "No problem.\p"
	.string "Anyways, can I enjoy my coffee alone,\n"
	.string "please? My Pokémon and I are tired…$"

Present_Cafe_Text_LookerOfCourse:
	.string "Oh, of course. Carry on.$"

Present_Cafe_Text_LookerAllsWellThatEndsWell:
	.string "Well, all's well that ends well!\p"
	.string "Landorus is back in the wild and the\n"
	.string "day is once again saved by…\p"
	.string "Looker!$"

Present_Cafe_Text_MayAgreed:
	.string "Yeah, I guess it was.\p"
	.string "You know, they should really have someone\n"
	.string "stationed out by the forest to tell\l"
	.string "travelers not to catch Landorus.$"

Present_Cafe_Text_LookerIndeedTheyShould:
	.string "Indeed, they should!\n"
	.string "Sadly, there is no funding for that.$"

Present_Cafe_Text_MayBummer:
	.string "Bummer.$"

Present_Cafe_Text_LookerCityHallWouldHaveBeenFaster:
	.string "Hmm… I think City Hall might have been\n"
	.string "the faster option after all…$"

Present_Cafe_Text_MayIGuessSo:
	.string "I guess so?$"

Present_Cafe_Text_LookerSurelyAnotherBattle:
	.string "Well, that is in the past. Surely\n"
	.string "another battle will be faster than\l"
	.string "going to City Hall now!$"

Present_Cafe_Text_MaySure:
	.string "Sure. I'm not complainin'.$"

Present_Cafe_Text_MayDefeated:
	.string "See? Now you have your answer!$"

Present_Cafe_Text_LookerIGuessThatWasFaster:
	.string "Hmm… I guess it was faster to simply\n"
	.string "battle it out…$"

Present_Cafe_Text_MayIKnowRight:
	.string "I know, right?$"

Present_Cafe_Text_LookerYouSeemResponsible:
	.string "Anyways…\p"
	.string "You seem like a responsible young\n"
	.string "lady, so why did you catch Landorus and\l"
	.string "throw the city into disarray?$"

Present_Cafe_Text_MayWellIDidntKnow:
	.string "Well, I didn't expect that a storm would\n"
	.string "erupt!\p"
	.string "I knew the power of Pokémon like Kyogre\n"
	.string "and Lugia and whatever, but I'd never\l"
	.string "heard of Landorus before…\p"
	.string "I thought it was just a strong Pokémon!$"

Present_Cafe_Text_LookerSensible:
	.string "Hmm… That seems sensible enough…\p"
	.string "Not everyone is going to be attuned to\n"
	.string "the local legends and customs of\l"
	.string "every city on Earth…\p"
	.string "Anyways!\p"
	.string "Come with me. We can release Landorus\n"
	.string "and bring this case to a close!$"

Present_Cafe_Text_MayHuh:
	.string "Huh? What?\p"
	.string "I thought this was something Team\n"
	.string "Aqua did?\p"
	.string "Why are you accusing ME?$"

Present_Cafe_Text_MayImJustConfused:
	.string "Okay, now I'm just confused.\n"
	.string "Where is this coming from?\p"
	.string "Are you sure you have the right person?$"

Present_Cafe_Text_MayWhatOkay:
	.string "Uhh… What…?\p"
	.string "I'd really rather not…\p"
	.string "Can we just settle this with a battle?$"

Present_Cafe_Text_LookerISuppose:
	.string "Hmm… I suppose that would be faster!\n"
	.string "All right then, let's battle!$"

Present_Cafe_Text_LookerHelloMayPreQuest:
	.string "Hello, young woman.\p"
	.string "Something is afoot! Landorus has gone\n"
	.string "missing and it is up to us to find out\l"
	.string "where it might have gone!\p"
	.string "Would you have any information on the\n"
	.string "matter?$"

Present_Cafe_Text_MayPrequest:
	.string "Uhh… Nope!\p"
	.string "I've been chillin' here ever since\n"
	.string "the storm started!\p"
	.string "I'll let you know if any shady guys\n"
	.string "come into this café, I guess!$"

Present_Cafe_Text_LookerWonderful:
	.string "Wonderful! I will be back later to\n"
	.string "investigate further…\p"
	.string "But please, report any wrongdoers to\n"
	.string "City Hall instead!\p"
	.string "They will be able to let me know,\n"
	.string "posthaste!$"

Present_Cafe_Text_MayUhhSure:
	.string "Umm… Sure?\p"
	.string "I will probably still be here?$"

Present_Cafe_Text_LookerHelloMay:
	.string "Hello, young woman.\p"
	.string "My name…\n"
	.string "Is Looker.\p"
	.string "Have you heard Team Aqua has set up\n"
	.string "shop in Porta Bella recently?\p"
	.string "I am trying to get to the bottom of\n"
	.string "their next devious scheme…\p"
	.string "Would you happen to know anything?$"

Present_Cafe_Text_MayPregame:
	.string "Nope!\p"
	.string "They messed with my home region not\n"
	.string "too long ago, but I didn't know they\l"
	.string "were still active…\p"
	.string "I'll keep my eyes peeled!$"

Present_Cafe_Text_LookerAhYes:
	.string "Ah, yes… Thank you.\p"
	.string "Please report anything you learn to\n"
	.string "City Hall as soon as you see it!$"

Present_Cafe_Text_SweetToothThankYou:
	.string "hi mister!!!!!!\p"
	.string "thank you so so so much!!!!!!\p"
	.string "i dont have much, but you can have\n"
	.string "this thing!!!!!!$"

Present_Cafe_Text_SweetToothOneRareCandy:
	.string "hi mister!!!!!\p"
	.string "i will have\p"
	.string "ONE\p"
	.string "rare candy please!!!!!$"

Present_Cafe_Text_CookSoMany:
	.string "But you've already had so many…$"

Present_Cafe_Text_SweetToothOoo:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "…oooOOoOOooOoooo…$"

Present_Cafe_Text_CookGivesIn:
	.string "Oof… Fine…\p"
	.string "You can have another…$"

Present_Cafe_Text_SweetToothYay:
	.string "yayy$"

Present_Cafe_Text_Cook:
	.string "Oh lord please help me…\p"
	.string "This girl came in and started demanding\n"
	.string "candies…\p"
	.string "I've never even seen her before…$"

Present_Cafe_Text_EmmaLovesLuvdiscs:
	.string "Aaaaaaaa!\p"
	.string "J'adore les Luvdiscs dans la\n"
	.string "baie!\p"
	.string "Elles sont si jolis…$"

Present_Cafe_Text_EmmaBonjour:
	.string "Bonjour!$"

Present_Cafe_Text_LookerBonjour:
	.string "Bonjour?$"

Present_Cafe_Text_EmmaComoCaVa:
	.string "Como ça va?$"

Present_Cafe_Text_LookerWhatDoISayHere:
	.string "(What do I say here…?)$"

Present_Cafe_Text_LookerBienMerci:
	.string "Bien, merçi. Ça va?$"

Present_Cafe_Text_LookerOui:
	.string "Oui…?$"

Present_Cafe_Text_LookerMal:
	.string "Pas bien…?$"

Present_Cafe_Text_EmmaLeaveYouAlone:
	.string "Ah…\p"
	.string "Je vous laisserai tranquille.$"

Present_Cafe_Text_EmmaTresBien:
	.string "Bien ça va! Je m'appelle Emma!\n"
	.string "Et vous?$"

Present_Cafe_Text_LookerMonNom:
	.string "Mon nom est Looker…?$"

Present_Cafe_Text_LookerJeSuisLooker:
	.string "Je suis Looker…?$"

Present_Cafe_Text_LookerJeMappelle:
	.string "Je m'appelle…\p"
	.string "Looker.$"

Present_Cafe_Text_EmmaEnchantee:
	.string "Enchantée, Looker!\p"
	.string "Mon Pokémon veulent voir Porta Bella\n"
	.string "et combattrent des combats, mais je\l"
	.string "veux boire du café toute la journée…\p"
	.string "Seriez vous en mesure un Pokémon avec\n"
	.string "vous et combattre avec lui,\l"
	.string "s'il vous plaît?$"

Present_Cafe_Text_LookerHuh:
    .string "(Huh…?)$"

Present_Cafe_Text_LookerSure:
	.string "Sure…?$"

Present_Cafe_Text_EmmaDontSpeakFrench:
	.string "Ah? Vous non parlez pas Français?\n"
	.string "Tant pis…$"

Present_Cafe_Text_LookerNoThanks:
	.string "Je ne veux pas.$"

Present_Cafe_Text_EmmaAhDaccord:
	.string "Ah, d'accord…$"

Present_Cafe_Text_LookerJePeux:
	.string "Bien sûr.$"

Present_Cafe_Text_EmmaMerciBeaucoup:
	.string "Merçi beaucoup!\p"
	.string "Quel Pokémon veux-vous?$"

Present_Cafe_Text_EmmaPostQuest:
	.string "Merçi beaucoup, Looker!$"

Present_Cafe_Text_LookerWrongAnswer:
	.string "(Drat, wrong response…)$"

Present_Cafe_Text_EmmaCoffeeDelicious:
	.string "Ahhhh…\p"
	.string "Ce café est délicieux…$"

Present_Cafe_Text_LeftIdolPrereqReward:
	.string "Finally, everyone's back!\p"
	.string "Now we just need to get our butts\n"
	.string "in gear and fix our rhythm…$"

Present_Cafe_Text_RightIdolPrereqReward:
	.string "Yay! Everyone's safe and sound!\p"
	.string "We still gotta practice for the show,\n"
	.string "but I'm still feeling really shaky…$"

Present_Cafe_Text_LisiaPrereqReward:
	.string "Alright girls, there's no time to\n"
	.string "waste now!\p"
	.string "We need to nail this routine before\n"
	.string "tonight if we wanna put on a good show!$"

Present_Cafe_Text_LisiaWorriedRight:
	.string "I got separated from Sophia in the\n"
	.string "woods but never saw her in the past…\p"
	.string "I wonder if she's still out there…$"

Present_Cafe_Text_LisiaWorriedLeft:
	.string "Bianca split up from us early on\n"
	.string "so I think she made it to safety…\p"
	.string "But still, I'm so scared for her…$"

Present_Cafe_Text_RightWorriedLisia:
	.string "Lisia and I got separated out in the\n"
	.string "forest and I haven't seen her since…\p"
	.string "I called her name so much and she never\n"
	.string "responded and I got lost and… and…\p"
	.string "I hope she's safe…$"

Present_Cafe_Text_RightWorriedLeft:
	.string "Bianca got to safety, I think…\n"
	.string "I saw her get into the Pokémon Center\n"
	.string "before the Mightyenas got to her…$"

Present_Cafe_Text_LeftWorried:
	.string "I saw Lisia and Sophia run into the\n"
	.string "forest while we were chased.\p"
	.string "Maybe you should look around there?$"