CutsceneForestPast_MapScripts::
	.byte 0

CutsceneForestPast_EventScript_IGottaFindAnabel::
	lockall
	msgbox CutsceneForestPast_Text_IGottaFindAnabel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

CutsceneForestPast_EventScript_AmIGoingTheRightWayL::
	lockall
	msgbox CutsceneForestPast_Text_AmIGoingTheRightWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight2
	waitmovement 0
	goto CutsceneForestPast_EventScript_AmIGoingTheRightWay

CutsceneForestPast_EventScript_AmIGoingTheRightWayR::
	lockall
	msgbox CutsceneForestPast_Text_AmIGoingTheRightWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft2
	waitmovement 0
	goto CutsceneForestPast_EventScript_AmIGoingTheRightWay
	end

CutsceneForestPast_EventScript_AmIGoingTheRightWayM::
	lockall
	msgbox CutsceneForestPast_Text_AmIGoingTheRightWay, MSGBOX_DEFAULT
	closemessage
	goto CutsceneForestPast_EventScript_AmIGoingTheRightWay
	end

CutsceneForestPast_EventScript_AmIGoingTheRightWay::
	delay 40
	applymovement LOCALID_PLAYER, CutsceneForestPast_Movement_LookAround
	waitmovement 0
	msgbox CutsceneForestPast_Text_SeemsRight, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	setvar VAR_CUTSCENE_STATE, 5
	releaseall
	end

CutsceneForestPast_Movement_LookAround:
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	step_end

CutsceneForestPast_Text_IGottaFindAnabel:
	.string "I gotta find Anabel…$"

CutsceneForestPast_Text_AmIGoingTheRightWay:
	.string "Am I even going the right way…?$"

CutsceneForestPast_Text_SeemsRight:
	.string "Yes, this seems like the right\n"
	.string "direction…\p"
	.string "I gotta head back to the city…$"