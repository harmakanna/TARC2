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

Present_School_EventScript_Twin::
	lockall
	releaseall
	end

Present_School_EventScript_Doubter::
	lock
	release
	end
	
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