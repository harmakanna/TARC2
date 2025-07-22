Past_TownHall_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Past_TownHall_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Past_TownHall_OnFrame
	.byte 0

Past_TownHall_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 6, Past_TownHall_EventScript_LookerWakesUpSetup
	end

Past_TownHall_EventScript_LookerWakesUpSetup::
	setflag FLAG_SYS_PREVENT_MAP_FADE
	setflag FLAG_SYS_B_DASH
	setobjectxyperm LOCALID_TOWNHALL_LOST_GIRL 1, 4
	setobjectmovementtype LOCALID_TOWNHALL_LOST_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_TOWNHALL_ANABEL 2, 4
	setobjectmovementtype LOCALID_TOWNHALL_ANABEL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_TOWNHALL_NURSE, 3, 3
	setobjectmovementtype LOCALID_TOWNHALL_NURSE, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_TOWNHALL_HAPPINY, 3, 2
	setobjectmovementtype LOCALID_TOWNHALL_HAPPINY, MOVEMENT_TYPE_FACE_LEFT
	return

Past_TownHall_OnFrame:
	goto_if_eq VAR_CUTSCENE_STATE, 6, Past_TownHall_EventScript_LookerWakesUp
	end

Past_TownHall_EventScript_LookerWakesUp::
	lockall
	delay 100
	msgbox Past_TownHall_Text_LookerUgh, MSGBOX_DEFAULT
	delay 48
	closemessage
	delay 30
	msgbox Past_TownHall_Text_SoundsLikeHesMoving, MSGBOX_DEFAULT
	delay 48
	closemessage
	delay 30
	msgbox Past_TownHall_Text_AnabelPleaseWakeUp, MSGBOX_DEFAULT
	delay 48
	closemessage
	delay 100
	msgbox Past_TownHall_Text_Dots, MSGBOX_DEFAULT
	delay 48
	closemessage
	delay 100
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_FROM_BLACK
	delay 48
	releaseall
	end

Past_TownHall_Text_SoundsLikeHesMoving:
	.string "???: Hey, he sounds like he's\n"
	.string "finally moving a bit!$"

Past_TownHall_Text_AnabelPleaseWakeUp:
	.string "Anabel: Looker, please wake up!\p"
	.string "I know you're strong enough to not\n"
	.string "let a few bruises do you in!$"

Past_TownHall_LookerUgh:
	.string "Looker: Ugh…$"

Past_TownHall_Text_Dots:
	.string "… … …\n"
	.string "… … …$"