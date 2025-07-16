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

PresentTown_EventScript_StartStorm1::
	lockall
	clearflag FLAG_HIDE_PORTO_BELLA_WILD_MONS
	applymovement LOCALID_PRESENTTOWN_ANABEL, PresentTown_Movement_AnabelWalkToPlayerBridge
	applymovement LOCALID_PLAYER, PresentTown_Movement_LookerWalkAcrossBridge1
	waitmovement 0
	goto PresentTown_EventScript_StartStorm
	end

PresentTown_EventScript_StartStorm2::
	lockall
	clearflag FLAG_HIDE_PORTO_BELLA_WILD_MONS
	applymovement LOCALID_PRESENTTOWN_ANABEL, PresentTown_Movement_AnabelWalkToPlayerBridge
	applymovement LOCALID_PLAYER, PresentTown_Movement_LookerWalkAcrossBridge2
	waitmovement 0
	goto PresentTown_EventScript_StartStorm
	end

PresentTown_EventScript_StartStorm::
	msgbox PresentTown_Text_AnabelTeamAquaResults, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_PRESENTTOWN_ANABEL, PresentTown_Movement_AnabelLookAtStorm2
	waitmovement 0
	msgbox PresentTown_Text_AnabelThatsStrange, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox PresentTown_Text_LookerWhatsWrong, MSGBOX_DEFAULT
	applymovement LOCALID_PRESENTTOWN_ANABEL, Common_Movement_FaceDown
	waitmovement 0
	msgbox PresentTown_Text_AnabelTakeACloserLook, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PRESENTTOWN_ANABEL, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	msgbox PresentTown_Text_LookerISeeIt, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_SetStormWeather
	doweather
	applymovement LOCALID_PRESENTTOWN_ANABEL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PRESENTTOWN_ANABEL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PRESENTTOWN_ANABEL, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox PresentTown_Text_AnabelWhatTheHeck, MSGBOX_DEFAULT
	closemessage
	msgbox PresentTown_Text_LookerThereWasOneThing, MSGBOX_DEFAULT
	closemessage
	setobjectxyperm LOCALID_PRESENTTOWN_WILDMON1, 20, 27
	setobjectxyperm LOCALID_PRESENTTOWN_WILDMON2, 20, 28
	setobjectxyperm LOCALID_PRESENTTOWN_WILDMON3, 19, 27
	addobject LOCALID_PRESENTTOWN_WILDMON1
	addobject LOCALID_PRESENTTOWN_WILDMON2
	addobject LOCALID_PRESENTTOWN_WILDMON3
	playse SE_PIN
	applymovement LOCALID_PRESENTTOWN_ANABEL, PresentTown_Movement_LookAtWildPokemon
	applymovement LOCALID_PLAYER, PresentTown_Movement_LookAtWildPokemon
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, PresentTown_Movement_CameraPanToWildPokemon
	applymovement LOCALID_PRESENTTOWN_WILDMON1, PresentTown_Movement_WildMon12
	applymovement LOCALID_PRESENTTOWN_WILDMON2, PresentTown_Movement_WildMon12
	applymovement LOCALID_PRESENTTOWN_WILDMON3, PresentTown_Movement_WildMon12
	waitmovement 0
	msgbox PresentTown_Text_AnabelLookOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAMERA, PresentTown_Movement_CameraPanToLookerRunning
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_PRESENTTOWN_ANABEL, PresentTown_Movement_AnabelRunIntoCityHall
	applymovement LOCALID_PLAYER, PresentTown_Movement_LookerRunIntoCityHall
	waitmovement 0
	playse SE_EXIT
	hideobjectat LOCALID_PRESENTTOWN_ANABEL, MAP_PRESENT_TOWN
	hideobjectat LOCALID_PLAYER, 0
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_HIDE_OUTSIDE_NPCS
	setflag FLAG_HIDE_ANABEL_PRESENTTOWN
	clearflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
	clearflag FLAG_HIDE_RANGERS
	setvar VAR_PORTO_BELLA_CITY_STATE, 2
	setvar VAR_CUTSCENE_STATE, 1
	warpsilent MAP_PRESENT_CITY_HALL_1F, 8, 8
	waitstate
	releaseall
	end

PresentTown_Movement_CameraPanToLookerRunning:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

PresentTown_Movement_AnabelRunIntoCityHall:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PresentTown_Movement_LookerRunIntoCityHall:
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PresentTown_Movement_WildMon12:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PresentTown_Movement_WildMon3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_right
	step_end

PresentTown_Movement_AnabelWalkToPlayerBridge:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PresentTown_Movement_LookerWalkAcrossBridge1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_right
	step_end

PresentTown_Movement_LookerWalkAcrossBridge2:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PresentTown_Movement_AnabelLookAtStorm1:
	face_up
	emote_question_mark
	delay_16
	delay_16
	delay_16
	step_end

PresentTown_Movement_AnabelLookAtStorm2:
	face_up
	emote_question_mark
	delay_16
	delay_16
	delay_16
	walk_up
	step_end

PresentTown_Movement_LookAtWildPokemon:
	face_left
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

PresentTown_Movement_CameraPanToWildPokemon:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PresentTown_EventScript_Matt::
	lockall
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PRESENTTOWN_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_Delay32
	waitmovement 0
	msgbox PresentTown_Text_MattTalkingToGrunt, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	faceplayer
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_Delay48
	waitmovement 0
	msgbox PresentTown_Text_MattTalkingToLooker, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	opendoor 15, 34
	waitdooranim
	applymovement LOCALID_PRESENTTOWN_MATT, PresentTown_Movement_MattEnterAquaCorp
	waitmovement 0
	setflag FLAG_HIDE_MATT_OUTSIDE
	hideobjectat LOCALID_PRESENTTOWN_MATT, MAP_PRESENT_TOWN
	closedoor 15, 34
	waitdooranim
	msgbox PresentTown_Text_AquaMemberFWait, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PRESENTTOWN_GRUNT, PresentTown_Movement_GruntFollowsMatt
	waitmovement 0
	msgbox PresentTown_Text_AquaMemberFNowHesMad, MSGBOX_DEFAULT
	closemessage
	setobjectxyperm LOCALID_PRESENTTOWN_GRUNT, 15, 35
	setobjectmovementtype LOCALID_PRESENTTOWN_GRUNT, MOVEMENT_TYPE_FACE_UP
	applymovement LOCALID_PRESENTTOWN_GRUNT, Common_Movement_FaceUp
	waitmovement 0
	setflag FLAG_TALKED_TO_MATT_OUTSIDE
	setvar VAR_PORTO_BELLA_CITY_STATE, 1
	removeobject LOCALID_PRESENTTOWN_MATT
	setobjectxyperm LOCALID_PRESENTTOWN_ANABEL, 37, 28
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
	lockall
	goto_if_set FLAG_TALKED_TO_MATT_OUTSIDE, PresentTown_EventScript_AquaMemberNowHesMad
	msgbox PresentTown_Text_AquaMemberFTalkingToMatt, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PresentTown_EventScript_AquaMemberNowHesMad::
	faceplayer
	msgbox PresentTown_Text_AquaMemberFNowHesMad, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PRESENTTOWN_GRUNT, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end

PresentTown_Text_AnabelTeamAquaResults:
	.string "Anabel: Mr. Looker.\p"
	.string "Looker: Ms. Anabel.\p"
	.string "Anabel: Did you get the chance\n"
	.string "to speak with the new leader\l"
	.string "of Team Aqua?\p"
	.string "Looker: Yes, Matt was rather\n"
	.string "obstinate…\p"
	.string "But I did not pick up on anything\n"
	.string "peculiar from their new operation.\p"
	.string "Anabel: Understood.\p"
	.string "I spoke with the mayor, and he has\n"
	.string "a vacant office in City Hall we can\l"
	.string "use while we stay in…$"

PresentTown_Text_AnabelThatsStrange:
	.string "That's strange…$"

PresentTown_Text_LookerWhatsWrong:
	.string "Looker: What seems to be the\n"
	.string "issue, Anabel?$"

PresentTown_Text_AnabelTakeACloserLook:
	.string "Anabel: Come take a closer look.$"

PresentTown_Text_LookerISeeIt:
	.string "Looker: That's odd…\n"
	.string "Are those storm clouds?\p"
	.string "Hurricane season doesn't start for\n"
	.string "another two months…$"

PresentTown_Text_AnabelWhatTheHeck:
	.string "Anabel: What the heck!? It was a\n"
	.string "perfect day just moments ago!\p"
	.string "Looker, are you positive Team Aqua's\n"
	.string "new operation is above board?$"

PresentTown_Text_LookerThereWasOneThing:
	.string "Looker: There was one thing Matt\n"
	.string "said which caught my attention…$"

PresentTown_Text_AnabelLookOut:
	.string "Anabel: Shoot!\n"
	.string "Wild Pokémon are running rampant!\p"
	.string "We need to get inside, stat!$"

PresentTown_Text_MattTalkingToGrunt:
	.string "Matt: Hehehe…\p"
	.string "The operation at the shrine went\n"
	.string "off without a hitch!\p"
	.string "With these results, we can…$"

PresentTown_Text_MattTalkingToLooker:
	.string "Huh? Who are you?$"

PresentTown_Text_AquaMemberFWait:
	.string "Grunt: Wait!$"

PresentTown_Text_AquaMemberFTalkingToMatt:
	.string "So about the operation at\n"
	.string "the east shrine…$"

PresentTown_Text_AquaMemberFNowHesMad:
	.string "Now you've done it!\p"
	.string "It'll take hours to get him\n"
	.string "to calm down…$"