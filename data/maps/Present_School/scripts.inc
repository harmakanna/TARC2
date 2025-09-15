Present_School_MapScripts::
	@map_script MAP_SCRIPT_ON_TRANSITION, PresentSchool_OnTransition
	.byte 0

PresentSchool_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, PresentSchool_EventScript_ForcePlayMusic
	end

PresentSchool_EventScript_ForcePlayMusic::
	playbgm MUS_DP_SUNYSHORE_DAY, FALSE
	return

PresentSchool_EventScript_LeftGameboyKid::
	lock
	speak LOCALID_LEFT_GAMEBOY_KID, DIR_EAST, Name_Left_Gameboy_Kid, PresentSchool_Text_LeftGameboyKidImPlaying
	returnqueststate QUEST_EUREKA
	goto_if_eq VAR_RESULT, 2, PresentSchool_EventScript_LeftGameboyKidGiveBattery
	speak LOCALID_RIGHT_GAMEBOY_KID, DIR_WEST, Name_Right_Gameboy_Kid, PresentSchool_Text_RightGameboyKidImPlaying
	goto_if_eq VAR_RESULT, 4, PresentSchool_EventScript_LeftGameboyKidGiveBatteryPostQuest
	closemessage
	release
	end

PresentSchool_EventScript_LeftGameboyKidGiveBattery::
	call Script_GetNPCFacingDirection
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_INeedYourHelp
	call_if_unset FLAG_ASKED_FOR_BATTERY, PresentSchool_EventScript_LeftGameboyKidIGuess
	checkitem ITEM_CELL_BATTERY
	goto_if_eq VAR_RESULT, TRUE, PresentSchool_EventScript_LeftGameboyKidNoWay
	goto_if_set FLAG_ASKED_FOR_BATTERY, PresentSchool_EventScript_LeftGameboyKidSecondBattery
	speakername NULL
	giveitem ITEM_CELL_BATTERY, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	call_if_set FLAG_ASKED_FOR_BATTERY, PresentSchool_EventScript_LeftGameboyKidGaveSecondBattery
	setflag FLAG_ASKED_FOR_BATTERY
	applymovement LOCALID_LEFT_GAMEBOY_KID, Common_Movement_FaceRight
	waitmovement 0
	closemessage
	release
	end

PresentSchool_EventScript_LeftGameboyKidSecondBattery::
	call_if_set FLAG_ASKED_FOR_SECOND_BATTERY, PresentSchool_EventScript_LeftGameboyKidUghFine
	call_if_unset FLAG_ASKED_FOR_SECOND_BATTERY, PresentSchool_EventScript_LeftGameboyKidLostBattery
	speakername NULL
	giveitem ITEM_CELL_BATTERY, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	call_if_set FLAG_ASKED_FOR_BATTERY, PresentSchool_EventScript_LeftGameboyKidGaveSecondBattery
	applymovement LOCALID_LEFT_GAMEBOY_KID, Common_Movement_FaceRight
	waitmovement 0
	closemessage
	release
	end

PresentSchool_EventScript_LeftGameboyKidGaveSecondBattery::
	setflag FLAG_ASKED_FOR_SECOND_BATTERY
	return

PresentSchool_EventScript_LeftGameboyKidGiveBatteryPostQuest::
	call Script_GetNPCFacingDirection
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_SoHeresTheThing
	checkitem ITEM_CELL_BATTERY
	goto_if_eq VAR_RESULT, TRUE, PresentSchool_EventScript_LeftGameboyKidNoWay
	call_if_set FLAG_ASKED_FOR_SECOND_BATTERY, PresentSchool_EventScript_LeftGameboyKidUghFine
	call_if_unset FLAG_ASKED_FOR_SECOND_BATTERY, PresentSchool_EventScript_LeftGameboyKidLostBattery
	speakername NULL
	giveitem ITEM_CELL_BATTERY, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ASKED_FOR_SECOND_BATTERY
	closemessage
	applymovement LOCALID_LEFT_GAMEBOY_KID, Common_Movement_FaceRight
	waitmovement 0
	release
	end

PresentSchool_EventScript_LeftGameboyKidIGuess::
	speak LOCALID_LEFT_GAMEBOY_KID, VAR_0x8005, Name_Left_Gameboy_Kid, PresentSchool_Text_LeftGameboyKidIGuess
	return

PresentSchool_EventScript_LeftGameboyKidUghFine::
	speak LOCALID_LEFT_GAMEBOY_KID, VAR_0x8005, Name_Left_Gameboy_Kid, PresentSchool_Text_LeftGameboyKidUghFine
	return
	
PresentSchool_EventScript_LeftGameboyKidLostBattery::
	speak LOCALID_LEFT_GAMEBOY_KID, VAR_0x8005, Name_Left_Gameboy_Kid, PresentSchool_Text_LeftGameboyKidLostBattery
	return

PresentSchool_EventScript_LeftGameboyKidNoWay::
	speak LOCALID_LEFT_GAMEBOY_KID, VAR_0x8005, Name_Left_Gameboy_Kid, PresentSchool_Text_LeftGameboyKidNoWay
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Unlucky
	closemessage
	release
	end

PresentSchool_EventScript_RightGameboyKid::
	lock
	returnqueststate QUEST_EUREKA
	goto_if_eq VAR_RESULT, 2, PresentSchool_EventScript_RightGameboyKidBattery
	speak LOCALID_LEFT_GAMEBOY_KID, DIR_EAST, Name_Left_Gameboy_Kid, PresentSchool_Text_LeftGameboyKidImPlaying
	speak LOCALID_RIGHT_GAMEBOY_KID, DIR_WEST, Name_Right_Gameboy_Kid, PresentSchool_Text_RightGameboyKidImPlaying
	closemessage
	release
	end

PresentSchool_EventScript_RightGameboyKidBattery::
	call Script_GetNPCFacingDirection
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_INeedYourHelp
	speak LOCALID_RIGHT_GAMEBOY_KID, VAR_0x8005, Name_Right_Gameboy_Kid, PresentSchool_Text_RightGameboyKidCantHelp
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Dots
	closemessage
	applymovement LOCALID_RIGHT_GAMEBOY_KID, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

Present_School_EventScript_KidsFaceDown::
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceDown
	applymovement LOCALID_SCHOOL_KID, Common_Movement_FaceDown
	return

Present_School_EventScript_KidsFaceUp::
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceUp
	applymovement LOCALID_SCHOOL_KID, Common_Movement_FaceUp
	return

Present_School_EventScript_KidsFaceLeft::
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceLeft
	applymovement LOCALID_SCHOOL_KID, Common_Movement_FaceLeft
	return

Present_School_EventScript_Twin::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_School_EventScript_TwinPreGenies
	speakername Name_Twin
	returnqueststate QUEST_INVESTIGATE_PROSPERITY
	goto_if_ne VAR_RESULT, 4, Present_School_EventScript_TwinPreGenies
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_LUXRAY
	switch VAR_RESULT
	case 1, Present_School_EventScript_TwinPreQuest
	case 2, Present_School_EventScript_TwinQuest
	case 3, Present_School_EventScript_TwinReward
	case 4, Present_School_EventScript_TwinPostQuest
	release
	end

Present_School_EventScript_TwinPreGenies::
	faceplayer
	msgbox Present_School_Text_TwinPreGenies, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_School_EventScript_TwinPreQuest::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_SCHOOL_TWIN, VAR_0x8005, Name_Twin, Present_School_Text_TwinAaa
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IsSomethingWrong
	speak LOCALID_SCHOOL_TWIN, VAR_0x8005, Name_Twin, Present_School_Text_TwinThisLameo
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_SCHOOL_KID, VAR_0x8005, Name_Doubter, Present_School_Text_DoubterItIsnt
	speak LOCALID_SCHOOL_TWIN, DIR_EAST, Name_Twin, Present_School_Text_TwinItIs
	call_if_eq VAR_FACING, DIR_SOUTH, Present_School_EventScript_KidsFaceUp
	call_if_eq VAR_FACING, DIR_NORTH, Present_School_EventScript_KidsFaceDown
	call_if_eq VAR_FACING, DIR_EAST, Present_School_EventScript_KidsFaceLeft
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_School_Text_LookerYouDontNeedToShout
	applymovement LOCALID_SCHOOL_KID, Common_Movement_FaceLeft
	speak LOCALID_SCHOOL_TWIN, VAR_0x8005, Name_Twin, Present_School_Text_TwinIKnow
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_SCHOOL_KID, DIR_WEST, Name_Doubter, Present_School_Text_DoubterNoYouWont
	speak LOCALID_SCHOOL_TWIN, DIR_EAST, Name_Twin, Present_School_Text_TwinYesIWill
	speak LOCALID_SCHOOL_KID, DIR_WEST, Name_Doubter, Present_School_Text_DoubterBozoBozoBozo
	speak LOCALID_SCHOOL_TWIN, DIR_EAST, Name_Twin, Present_School_Text_TwinIdiot
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, Looker_Text_ImOnTheCaseDoubt
	startquest QUEST_LUXRAY
	call_if_set FLAG_CAUGHT_LUXRAY, Present_School_EventScript_SetTwinReward
	call_if_set FLAG_CAUGHT_LUXRAY_DARK, Present_School_EventScript_SetTwinReward
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_School_EventScript_SetTwinReward::
	questmenu QUEST_MENU_SET_REWARD, QUEST_LUXRAY
	return
	
Present_School_EventScript_TwinQuest::
	speak LOCALID_SCHOOL_KID, DIR_WEST, Name_Doubter, Present_School_Text_DoubterBozoBozoBozo
	speak LOCALID_SCHOOL_TWIN, DIR_EAST, Name_Twin, Present_School_Text_TwinStupidBabyIdiot
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Dots
	closemessage
	release
	end

Present_School_EventScript_TwinReward::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_SCHOOL_TWIN, VAR_0x8005, Name_Twin, Present_School_Text_TwinDidYouBringIt
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Present_School_EventScript_TwinNothingChosen
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_LUXRAY, Present_School_EventScript_TwinQuestCompletion
	goto_if_eq VAR_RESULT, SPECIES_LUXRAY_DARK, Present_School_EventScript_TwinSecretQuestCompletion
	speak LOCALID_SCHOOL_TWIN, VAR_0x8005, Name_Twin, Present_School_Text_TwinThatsNotLuxray
	closemessage
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_School_EventScript_TwinNothingChosen::
	speak LOCALID_SCHOOL_TWIN, VAR_0x8005, Name_Twin, Present_School_Text_TwinNoMonSelected
	closemessage
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_School_EventScript_TwinQuestCompletion::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_School_Text_LookerHereIsLuxray
	speak LOCALID_SCHOOL_TWIN, VAR_0x8005, Name_Twin, Present_School_Text_TwinWhat
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight 
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceRight
	speak LOCALID_SCHOOL_KID, DIR_WEST, Name_Doubter, Present_School_Text_DoubterIWin
	speak LOCALID_SCHOOL_TWIN, DIR_EAST, Name_Twin, Present_School_Text_TwinNoWay
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, Present_School_EventScript_TwinRunAwayAround
	call_if_ne VAR_FACING, DIR_NORTH, Present_School_EventScript_TwinRunAway
	removeobject LOCALID_SCHOOL_TWIN
	delay 40
	applymovement LOCALID_SCHOOL_KID, Common_Movement_WalkLeft
	call_if_eq VAR_FACING, DIR_NORTH, Present_School_EventScript_TurnLookerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, Present_School_EventScript_TurnLookerSouth
	call_if_eq VAR_FACING, DIR_EAST, Present_School_EventScript_TurnLookerEast
	waitmovement LOCALID_SCHOOL_KID
	setobjectxyperm LOCALID_SCHOOL_KID, 1, 4
	speak LOCALID_SCHOOL_KID, VAR_0x8005, Name_Doubter, Present_School_Text_DoubterReward
	speakername NULL
	giveitem ITEM_TM_HELPING_HAND, 1 @replaced with Helping Hand 
	completequest QUEST_LUXRAY
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_School_EventScript_TurnLookerNorth::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	return

Present_School_EventScript_TurnLookerSouth::
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	return
	
Present_School_EventScript_TurnLookerEast::
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	return
	
Present_School_EventScript_TwinRunAway::
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_SCHOOL_KID, Common_Movement_FaceDown
	applymovement LOCALID_SCHOOL_TWIN, Present_School_Movement_TwinRunAway
	waitmovement 0
	return

Present_School_Movement_TwinRunAway:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Present_School_EventScript_TwinRunAwayAround::
	applymovement LOCALID_PLAYER, Present_School_Movement_WatchTwinRunAwayAround
	applymovement LOCALID_SCHOOL_KID, Present_School_Movement_WatchTwinRunAwayAround
	applymovement LOCALID_SCHOOL_TWIN, Present_School_Movement_TwinRunAwayAround
	waitmovement 0
	return

Present_School_Movement_WatchTwinRunAwayAround::
	delay_8
	face_left
	delay_16
	face_down
	step_end

Present_School_Movement_TwinRunAwayAround:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Present_School_EventScript_TwinSecretQuestCompletion::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_School_Text_LookerHereIsLuxray
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceRight
	speak LOCALID_SCHOOL_KID, VAR_0x8005, Name_Doubter, Present_School_Text_DoubterHuh
	speak LOCALID_SCHOOL_TWIN, DIR_EAST, Name_Twin, Present_School_Text_TwinThatsRightIdiot
	speak LOCALID_SCHOOL_KID, DIR_WEST, Name_Doubter, Present_School_Text_DoubterNoWay
	closemessage
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceDown
	applymovement LOCALID_SCHOOL_KID, Present_School_Movement_DoubterRunAway
	call_if_eq VAR_FACING, DIR_NORTH, Present_School_EventScript_DelayLookerFaceDown
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement LOCALID_SCHOOL_KID
	removeobject LOCALID_SCHOOL_KID
	delay 40
	call_if_eq VAR_FACING, DIR_NORTH, Present_School_EventScript_TurnLookerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, Present_School_EventScript_TurnLookerSouth
	call_if_eq VAR_FACING, DIR_EAST, Present_School_EventScript_TurnLookerEast
	waitmovement 0
	speak LOCALID_SCHOOL_TWIN, VAR_0x8005, Name_Twin, Present_School_Text_TwinReward
	speakername NULL
	giveitem ITEM_CHOICE_BAND
	closemessage
	playse SE_PIN
	applymovement LOCALID_SCHOOL_TWIN, Common_Movement_FaceRightQuestionMark
	waitmovement 0
	delay 50
	speak LOCALID_SCHOOL_TWIN, VAR_0x8005, Name_Twin, Present_School_Text_TwinHeDroppedThis
	speakername NULL
	giveitem ITEM_TM_HELPING_HAND, 1 @replaced with Helping Hand 
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_LUXRAY, 0
	completequest QUEST_LUXRAY
	closemessage
	setflag FLAG_SHOWN_DARK_LUXRAY
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_School_EventScript_DelayLookerFaceDown::
	delay 16
	return

Present_School_Movement_DoubterRunAway:
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Present_School_EventScript_TwinPostQuest::
	faceplayer
	speakername Name_Twin
	msgbox Present_School_Text_TwinPostQuest
	closemessage
	release
	end

Present_School_EventScript_Doubter::
	lock
	returnqueststate QUEST_LUXRAY
	switch VAR_RESULT
	case 2, Present_School_EventScript_TwinQuest
	case 3, Present_School_EventScript_TwinQuest
	case 4, Present_School_EventScript_DoubterPostQuest
	faceplayer
	call_if_set FLAG_SYS_MAIN_GAME_START, Present_School_EventScript_GiveDoubterName
	msgbox Present_School_Text_DoubterPreGenies, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCHOOL_KID, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
Present_School_EventScript_GiveDoubterName::
	speakername Name_Doubter
	return

Present_School_EventScript_DoubterPostQuest::
	faceplayer
	speakername Name_Doubter
	msgbox Present_School_Text_DoubterPostQuest
	closemessage
	release
	end

Present_School_EventScript_Teacher::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_LUXRAY, 0
	goto_if_eq VAR_RESULT, TRUE, Present_School_EventScript_TeacherSecret
	lock
	faceplayer
	speakername Name_Teacher
	msgbox Present_School_Text_TeacherAllTheyCare, MSGBOX_DEFAULT
	applymovement LOCALID_SCHOOL_TEACHER, Common_Movement_WalkInPlaceFasterLeft
	playse SE_SELECT
	msgbox Present_School_Text_TeacherSeeThatKid, MSGBOX_DEFAULT
	waitmovement LOCALID_SCHOOL_TEACHER
	call_if_eq VAR_FACING, DIR_EAST, Present_School_EventScript_TurnTeacherLeft
	call_if_ne VAR_FACING, DIR_EAST, Present_School_EventScript_TurnTeacherRight
	playse SE_SELECT
	msgbox Present_School_Text_TeacherWillBelieveAnything, MSGBOX_DEFAULT
	waitmovement LOCALID_SCHOOL_TEACHER
	closemessage
	applymovement LOCALID_SCHOOL_TEACHER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_School_EventScript_TurnTeacherLeft::
	applymovement LOCALID_SCHOOL_TEACHER, Common_Movement_FaceLeft
	return
	
Present_School_EventScript_TurnTeacherRight::
	applymovement LOCALID_SCHOOL_TEACHER, Common_Movement_FaceRight
	return
	
Present_School_EventScript_TeacherSecret::
	msgbox Present_School_Text_TeacherSurprised, MSGBOX_NPC
	end

Present_School_EventScript_BackBoy::
	lock
	msgbox Present_School_Text_BackBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_School_EventScript_LassStudent::
	lock
	faceplayer
	speakername Name_Girl
	msgbox Present_School_Text_LassStudent, MSGBOX_DEFAULT
	applymovement LOCALID_SCHOOL_LASS_STUDENT, Common_Movement_FaceRight
	playse SE_SELECT
	msgbox Present_School_Text_LassThoseBoys, MSGBOX_DEFAULT
	waitmovement LOCALID_SCHOOL_LASS_STUDENT
	closemessage
	applymovement LOCALID_SCHOOL_LASS_STUDENT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_School_Text_LassStudent:
	.string "Y'know, sometimes I wonder if anyone\n"
	.string "else in this class actually cares about\l"
	.string "their studies…$"
	
Present_School_Text_LassThoseBoys:
	.string "Those boys over there? They go through\n"
	.string "batteries like nobody's business…$"

Present_School_Text_BackBoy:
	.string "The boy is looking down at his phone.\n"
	.string "His eyes are glazed over.\p"
	.string "He seems to be watching a video about\n"
	.string "a legendary trainer named Doryan.$"

Present_School_Text_TeacherAllTheyCare:
	.string "Kids these days aren't interested in\n"
	.string "learning any more…\p"
	.string "All they care about are Pokémon hacks…$"

Present_School_Text_TeacherSeeThatKid:
	.string "See that little girl over there?\p"
	.string "She thinks there's such a thing as a\n"
	.string "dark-type Luxray.$"

Present_School_Text_TeacherWillBelieveAnything:
	.string "Kids will believe anything, I swear…$"

Present_School_Text_TeacherSurprised:
	.string "Color me surprised… There IS a dark-\n"
	.string "type Luxray out there?\p"
	.string "Something feels very wrong to me…$"

Present_School_Text_LookerHereIsLuxray:
	.string "Here's a Luxray.$"

Present_School_Text_TwinWhat:
	.string "wait…\p"
	.string "WHAAAAAAAAAAT!!!$"

Present_School_Text_DoubterIWin:
	.string "HAHAHAHAHAHA\p"
	.string "I WIN BOZO!!!!$"

Present_School_Text_TwinNoWay:
	.string "NO\p"
	.string "NO WAY\p"
	.string "THIS CANT BE REALL!!!!\p"
	.string "WAAAAAAAAAAAAH!!!!!!!!$"

Present_School_Text_DoubterReward:
	.string "hehehe! thanks for showing her a\n"
	.string "REAL luxray sir!\p"
	.string "now she knows not to believe the LIES\n"
	.string "in POKéMON HACKS!\p"
	.string "you can have this!$"

Present_School_Text_DoubterPostQuest:
	.string "thanks for showing her a REAL luxray!\n"
	.string "that BOZO cant handle the TRUTH at ALL!$"

Present_School_Text_LookerYouDontNeedToShout:
	.string "You don't need to shout at each\n"
	.string "other. What if you talk-$"

Present_School_Text_DoubterHuh:
	.string "wait…\p"
	.string "HUUUUUUUUUH!?!?!?$"

Present_School_Text_TwinThatsRightIdiot:
	.string "AHAHAHAHAHAHA!!!!!\p"
	.string "THATS RIGHT STUPID!!!!\p"
	.string "READ IT AND WEEP!!!!!!!$"

Present_School_Text_DoubterNoWay:
	.string "NO WAY THATS A REAL LUXRAY\p"
	.string "THIS IS WRONG\p"
	.string "YOU BROUGHT A FAKE YOU FAKER\p"
	.string "WAAAAAAAAAAAAH!!!!!!!!$"
	
Present_School_Text_TwinReward:
	.string "HAHAHAHA!!!\p"
	.string "I KNEW LUXRAY WAS A DARK TYPE!!!\p"
	.string "POKéMON HACKS ARE NEVER WRONG!!!\p"
	.string "thanks sir have this as thanks$"

Present_School_Text_TwinHeDroppedThis:
	.string "oh? he dropped something!\p"
	.string "well i dont want it\n"
	.string "its yours now, here!$"

Present_School_Text_TwinPostQuest:
	.string "I KNEW LUXRAY WAS A DARK TYPE!!!\p"
	.string "THAT IDIOT WAS WRONG THE WHOLE TIME!!!$"
	
Present_School_Text_TwinDidYouBringIt:
	.string "SO SIR!? DID YOU BRING ME A DARK\n"
	.string "LUXRAY!?$"

Present_School_Text_TwinThatsNotLuxray:
	.string "YOU LAMEO! THAT'S NOT A LUXRAY!!!$"

Present_School_Text_TwinNoMonSelected:
	.string "AAAAA HURRY UP AND BRING LUXRAY!!!$"

Present_School_Text_TwinAaa:
	.string "AAAAAAAAAAAAAAAAAAAAAA$"

Present_School_Text_TwinThisLameo:
	.string "this lameo is making FUN of me\n"
	.string "because he thinks luxray is NOT a\l"
	.string "dark type!!!\p"
	.string "but luxray IS a dark type!!!! my\n"
	.string "pokémon hack says so!!!!$"

Present_School_Text_DoubterItIsnt:
	.string "thats cuz IT ISNT!!!$"

Present_School_Text_TwinItIs:
	.string "IT IS!!!$"
	
Present_School_Text_TwinIKnow:
	.string "I KNOW!!!!\p"
	.string "what if you CAUGHT ME a LUXRAY so then\n"
	.string "we can PROVE its a DARK TYPE!!!\p"
	.string "ill show this LAMEO that hes wrong!!!$"

Present_School_Text_DoubterNoYouWont:
	.string "no you WONT\p"
	.string "cuz it ISNT!!!!\p"
	.string "BOZO!!!$"

Present_School_Text_TwinYesIWill:
	.string "YES I WILL IDOIT$"

Present_School_Text_DoubterBozoBozoBozo:
	.string "BOZO BOZO BOZO$"

Present_School_Text_TwinIdiot:
	.string "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n"
	.string "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\p"
	.string "STUPID BABY IDIOT!!!!!!!$"

Present_School_Text_TwinStupidBabyIdiot:
	.string "STUPID BABY IDIOT$"

Present_School_Text_TwinPreGenies:
	.string "HI\p"
	.string "HI HEY HI\p"
	.string "MISTER DID YOU KNOW!!!\p"
	.string "LUXRAY\p"
	.string "IS A DARK TYPE????\p"
	.string "MY POKéMON HACK SAYS SO!!!!$"

Present_School_Text_DoubterPreGenies:
	.string "this BOZO thinks LUXRAY is DARK!\p"
	.string "she plays too many VIDEO GAMES!!\p"
	.string "does she have EYES!?\p"
	.string "BOZO!!!$"

PresentSchool_Text_LeftGameboyKidIGuess:
	.string "Huh? You want a battery?\n"
	.string "Hmmm…\p"
	.string "What? You're telling me you play\n"
	.string "Pokémon hacks all the time?\p"
	.string "Sure, I guess I can spare you one…$"

PresentSchool_Text_LeftGameboyKidImPlaying:
	.string "I'm playing Pokémon hacks on a\n"
	.string "flash cart on MY Gameboy!$"

PresentSchool_Text_RightGameboyKidImPlaying:
	.string "Oh yeah!?\p"
	.string "Well I'M playing the hit new GBA\n"
	.string "game, Shantae: Risky Revolution,\l"
	.string "on my Gameboy!$"

PresentSchool_Text_RightGameboyKidCantHelp:
	.string "You need a battery?\p"
	.string "No way! This is my last one!\p"
	.string "Ask him!$"

PresentSchool_Text_LeftGameboyKidNoWay:
	.string "What?\n"
	.string "Why do you want ANOTHER battery?\p"
	.string "You got one right there, don't try\n"
	.string "to pull a fast one on me!$"

PresentSchool_Text_LeftGameboyKidLostBattery:
	.string "What? What happened to the last\n"
	.string "battery I gave you?\p"
	.string "I GUESS you can have another…\p"
	.string "But no more!$"

PresentSchool_Text_LeftGameboyKidUghFine:
	.string "Ugh, FINE…\p"
	.string "I guess I can give you YET ANOTHER\n"
	.string "battery…\p"
	.string "You moocher…$"
	