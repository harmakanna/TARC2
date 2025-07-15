PresentTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PresentTown_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PresentTown_OnTransition
	.byte 0

PresentTown_OnLoad:
	givemon SPECIES_GROWLITHE, 48
	givemon SPECIES_TOXICROAK, 48
	end

PresentTown_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetStormWeather
	end

PresentTown_EventScript_StartStorm::
	lockall
	call Common_EventScript_SetStormWeather
	doweather
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_HIDE_OUTSIDE_NPCS
	clearflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
	setvar VAR_PORTO_BELLA_CITY_STATE, 2
	releaseall
	end

PresentTown_EventScript_Matt::
	lockall
	applymovement LOCALID_MATT, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PRESENTTOWN_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_MATT, Common_Movement_Delay32
	waitmovement 0
	msgbox PresentTown_Text_MattTalkingToGrunt, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	faceplayer
	applymovement LOCALID_MATT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MATT, Common_Movement_Delay48
	waitmovement 0
	msgbox PresentTown_Text_MattTalkingToLooker, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	opendoor 15, 34
	waitdooranim
	applymovement LOCALID_MATT, PresentTown_Movement_MattEnterAquaCorp
	waitmovement 0
	setflag FLAG_HIDE_MATT_OUTSIDE
	hideobjectat LOCALID_MATT, MAP_PRESENT_TOWN
	closedoor 15, 34
	waitdooranim
	msgbox PresentTown_Text_AquaMemberF_Wait, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PRESENTTOWN_GRUNT, PresentTown_Movement_GruntFollowsMatt
	waitmovement 0
	msgbox PresentTown_Text_AquaMemberF_NowHesMad, MSGBOX_DEFAULT
	closemessage
	setobjectxyperm LOCALID_PRESENTTOWN_GRUNT, 15, 35
	setobjectmovementtype LOCALID_PRESENTTOWN_GRUNT, MOVEMENT_TYPE_FACE_UP
	applymovement LOCALID_PRESENTTOWN_GRUNT, Common_Movement_FaceUp
	waitmovement 0
	setflag FLAG_TALKED_TO_MATT_OUTSIDE
	setvar VAR_PORTO_BELLA_CITY_STATE, 1
	removeobject LOCALID_MATT
	releaseall
	end

PresentTown_Movement_MattEnterAquaCorp:
	walk_fast_up
	step_end

PresentTown_Movement_GruntFollowsMatt:
	walk_left
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_player
	step_end

PresentTown_EventScript_AquaMemberF::
	lock
	goto_if_set FLAG_TALKED_TO_MATT_OUTSIDE, PresentTown_EventScript_AquaMemberNowHesMad
	msgbox PresentTown_Text_AquaMemberF_TalkingToMatt, MSGBOX_DEFAULT
	closemessage
	release
	end

PresentTown_EventScript_AquaMemberNowHesMad::
	faceplayer
	msgbox PresentTown_Text_AquaMemberF_NowHesMad, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PRESENTTOWN_GRUNT, Common_Movement_FaceUp
	waitmovement 0
	release
	end

PresentTown_Text_MattTalkingToGrunt:
	.string "Matt: Hehehe…\p"
	.string "The operation at the shrine went\n"
	.string "off without a hitch!\p"
	.string "With these results, we can…$"

PresentTown_Text_MattTalkingToLooker:
	.string "Huh? Who are you?$"

PresentTown_Text_AquaMemberF_Wait:
	.string "Grunt: Wait!$"

PresentTown_Text_AquaMemberF_TalkingToMatt:
	.string "So about the operation at\n"
	.string "the east shrine…$"

PresentTown_Text_AquaMemberF_NowHesMad:
	.string "Now you've done it!\p"
	.string "It'll take hours to get him\n"
	.string "to calm down…$"