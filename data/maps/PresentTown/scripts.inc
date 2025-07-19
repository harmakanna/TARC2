PresentTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PresentTown_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PresentTown_OnTransition
	.byte 0

PresentTown_OnLoad:
	call_if_eq VAR_CUTSCENE_STATE, 2, PresentTown_EventScript_ChangeAnabelFollowerText
	call_if_unset FLAG_LOOKER_STARTERS, PresentTown_EventScript_GiveLookerStarters
	call_if_set FLAG_LOCK_CITY_DOORS, PresentTown_EventScript_LockCityDoors
	end

PresentTown_EventScript_ChangeAnabelFollowerText::
	setflag FLAG_STEPPED_OUT_OF_CITY_HALL
	return

@ debug script so Looker isn't flooded with Growlithe and Toxicroak 
PresentTown_EventScript_GiveLookerStarters::
	givemon SPECIES_GROWLITHE, 48
	givemon SPECIES_TOXICROAK, 48
	return 

PresentTown_EventScript_LockCityDoors::
	setmetatile 26, 12, METATILE_PresentTown_Locked_Door, TRUE
	setmetatile 32, 12, METATILE_PresentTown_Locked_Door, TRUE
	setmetatile 21, 16, METATILE_PresentTown_Locked_Door, TRUE
	setmetatile 18, 26, METATILE_PresentTown_Locked_Door, TRUE
	setmetatile 22, 26, METATILE_PresentTown_Locked_Door, TRUE
	setmetatile 60, 26, METATILE_PresentTown_Locked_Door, TRUE
	setmetatile 55, 33, METATILE_PresentTown_Locked_Door, TRUE
	setmetatile 59, 33, METATILE_PresentTown_Locked_Door, TRUE
	setmetatile 15, 34, METATILE_PresentTown_Locked_Door, TRUE
	setmetatile 23, 34, METATILE_PresentTown_Locked_Door, TRUE
	setmetatile 55, 18, METATILE_PresentTown_Locked_Gym_Door, TRUE
	return

PresentTown_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetStormWeather
	call_if_set FLAG_TALKED_TO_MATT_OUTSIDE, PresentTown_EventScript_AquaMemberFPositioning
	call_if_eq VAR_PORTO_BELLA_CITY_STATE, 1, PresentTown_EventScript_PrepareAnabelForCutscene
	end

PresentTown_EventScript_AquaMemberFPositioning::
	setobjectxyperm LOCALID_PRESENTTOWN_GRUNT, 15, 35
	setobjectmovementtype LOCALID_PRESENTTOWN_GRUNT, MOVEMENT_TYPE_FACE_UP
	return
	
PresentTown_EventScript_PrepareAnabelForCutscene::
	setobjectxyperm LOCALID_PRESENTTOWN_ANABEL, 37, 28
	return
	
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
	msgbox PresentTown_Text_AnabelLookerGreet, MSGBOX_DEFAULT
	applymovement LOCALID_PRESENTTOWN_ANABEL, Common_Movement_WalkInPlaceFasterLeft
	msgbox PresentTown_Text_AnabelDidYouGetTheChance, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox PresentTown_Text_LookerObstinate, MSGBOX_DEFAULT
	applymovement LOCALID_PRESENTTOWN_ANABEL, Common_Movement_WalkInPlaceFasterLeft
	msgbox PresentTown_Text_AnabelUnderstood, MSGBOX_DEFAULT
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
	playse SE_THUNDERSTORM
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
	applymovement LOCALID_PRESENTTOWN_WILDMON3, PresentTown_Movement_WildMon3
	applymovement LOCALID_CAMERA, Common_Movement_Delay32
	waitmovement 0
	msgbox PresentTown_Text_AnabelLookOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PRESENTTOWN_ANABEL, PresentTown_Movement_AnabelRunIntoCityHall
	applymovement LOCALID_PLAYER, PresentTown_Movement_LookerRunIntoCityHall
	applymovement LOCALID_PRESENTTOWN_WILDMON1, PresentTown_Movement_WildMon1Chase
	applymovement LOCALID_PRESENTTOWN_WILDMON2, PresentTown_Movement_WildMon2Chase
	applymovement LOCALID_PRESENTTOWN_WILDMON3, PresentTown_Movement_WildMon3Chase
	applymovement LOCALID_CAMERA, Common_Movement_Delay48
	waitmovement 0
	playse SE_EXIT
	hideobjectat LOCALID_PRESENTTOWN_ANABEL, MAP_PRESENT_TOWN
	hideobjectat LOCALID_PLAYER, 0
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_LOCK_CITY_DOORS
	setflag FLAG_HIDE_OUTSIDE_NPCS
	setflag FLAG_HIDE_AQUA_GRUNT_OUTSIDE
	setflag FLAG_HIDE_ANABEL_PRESENTTOWN
	clearflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
	clearflag FLAG_HIDE_RANGERS
	clearflag FLAG_HIDE_CITYHALL_1F_MAYOR
	clearflag FLAG_HIDE_ANABEL_CITYHALL
	setvar VAR_PORTO_BELLA_CITY_STATE, 2
	setvar VAR_CUTSCENE_STATE, 1
	fwdtime 13, 30
	warp MAP_PRESENT_CITY_HALL_1F, 8, 8
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

PresentTown_Movement_WildMon1Chase:
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
	step_end

PresentTown_Movement_WildMon2Chase:
	delay_16
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
	step_end

PresentTown_Movement_WildMon3Chase:
	delay_8
	walk_fast_up
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
	step_end

PresentTown_Movement_AnabelWalkToPlayerBridge:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PresentTown_Movement_LookerWalkAcrossBridge1:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
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
	delay_16
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
	goto_if_eq VAR_FACING, DIR_EAST, PresentTown_EventScript_MattFromTheSide
	msgbox PresentTown_Text_MattWhoAreYou, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox PresentTown_Text_LookerMyNameIs, MSGBOX_DEFAULT
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_WalkInPlaceFasterDown
	msgbox PresentTown_Text_MattSeriously, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox PresentTown_Text_LookerIWillNotJustScram, MSGBOX_DEFAULT
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_WalkInPlaceFasterDown
	msgbox PresentTown_Text_MattScrewOff, MSGBOX_DEFAULT
	closemessage
	playse SE_EFFECTIVE
	applymovement LOCALID_PLAYER, PresentTown_Movement_LookerPushedByMatt
	applymovement LOCALID_PRESENTTOWN_MATT, PresentTown_Movement_MattPushLooker
	waitmovement 0
	msgbox PresentTown_Text_LookerOuch, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	opendoor 15, 34
	waitdooranim
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	goto PresentTown_EventScript_FinishMattCutscene
	end

PresentTown_EventScript_MattFromTheSide::
	msgbox PresentTown_Text_MattWhoAreYou, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox PresentTown_Text_LookerMyNameIs, MSGBOX_DEFAULT
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_WalkInPlaceFasterLeft
	msgbox PresentTown_Text_MattSeriously, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox PresentTown_Text_LookerIWillNotJustScram, MSGBOX_DEFAULT
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_WalkInPlaceFasterLeft
	msgbox PresentTown_Text_MattScrewOff, MSGBOX_DEFAULT
	closemessage
	playse SE_EFFECTIVE
	applymovement LOCALID_PLAYER, PresentTown_Movement_LookerPushedByMattSide
	applymovement LOCALID_PRESENTTOWN_MATT, PresentTown_Movement_MattPushLookerSide
	waitmovement 0
	msgbox PresentTown_Text_LookerOuch, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	opendoor 15, 34
	waitdooranim
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	goto PresentTown_EventScript_FinishMattCutscene
	end

PresentTown_EventScript_FinishMattCutscene::
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

PresentTown_Movement_MattPushLooker:
	lock_facing_direction
	walk_faster_down
	walk_fast_up
	unlock_facing_direction
	step_end

PresentTown_Movement_MattPushLookerSide:
	lock_facing_direction
	walk_faster_left
	walk_fast_right
	unlock_facing_direction
	step_end

PresentTown_Movement_LookerPushedByMatt:
	lock_facing_direction
	delay_8
	walk_faster_down
	step_end

PresentTown_Movement_LookerPushedByMattSide:
	lock_facing_direction
	delay_8
	walk_faster_left
	step_end

PresentTown_Movement_MattEnterAquaCorp:
	walk_fast_up
	step_end

PresentTown_Movement_GruntFollowsMatt:
	walk_fast_left
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

PresentTown_EventScript_NoBusinessInTheForest::
	lockall
	msgbox PresentTown_Text_LookerNoBusinessInTheForest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end 

PresentTown_EventScript_NoBusinessInTheForest2::
	lockall
	msgbox PresentTown_Text_LookerNoBusinessInTheForest2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end 

PresentTown_EventScript_CatchProsperityRangerAttention::
	lockall
	applymovement LOCALID_PRESENT_PROSPERITY_RANGER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceRight
	msgbox PresentTown_Text_ProsperityRangerHey, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox PresentTown_Text_LookerSorry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceDown
	releaseall
	end

PresentTown_EventScript_ProsperityRanger::
	msgbox PresentTown_Text_ProsperityOhNoIWasSupposedTo, MSGBOX_NPC
	end

PresentTown_EventScript_PeaceRanger::
	lockall
	goto_if_eq VAR_CUTSCENE_STATE, 2, PresentTown_EventScript_CatchPeaceRangerAttentionTalked
	releaseall
	end

PresentTown_EventScript_CatchPeaceRangerAttentionTalked::
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_WalkInPlaceFasterDown
	turnobject OBJ_EVENT_ID_NPC_FOLLOWER, DIR_NORTH
	msgbox PresentTown_Text_PeaceRangerAlert, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox PresentTown_Text_LookerImHereToHelpFind, MSGBOX_DEFAULT
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_WalkInPlaceFasterDown
	msgbox PresentTown_Text_PeaceRangerWeCouldAlwaysUseMoreHands, MSGBOX_DEFAULT
	playse SE_SELECT
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_FaceUp
	msgbox PresentTown_Text_PeaceRangerUpThatWay, MSGBOX_DEFAULT
	playse SE_SELECT
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_FaceDown
	msgbox PresentTown_Text_PeaceRangerAsAResult, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox PresentTown_Text_LookerUnderstood, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkInPlaceFasterUp
	msgbox PresentTown_Text_AnabelTheresNoTimeToLose, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement LOCALID_PRESENT_PEACE_RANGER, PresentTown_Movement_RunIntoForest
	applymovement LOCALID_PLAYER, PresentTown_Movement_RunIntoForestLong
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, PresentTown_Movement_RunIntoForestLong
	removeobject LOCALID_PRESENT_PEACE_RANGER
	removeobject LOCALID_PLAYER
	removeobject OBJ_EVENT_ID_NPC_FOLLOWER
	fadescreen FADE_TO_BLACK
	destroyfollowernpc
	setvar VAR_CUTSCENE_STATE, 3
	setflag FLAG_SYS_PREVENT_MAP_FADE
	warp MAP_CUTSCENE_FOREST, 10, 17
	releaseall
	end

PresentTown_EventScript_CatchPeaceRangerAttention1::
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceLeft
	playse SE_PIN
	applymovement LOCALID_PRESENT_PEACE_RANGER, PresentTown_Movement_PeaceRangerEmoteTurn
	waitmovement 0
	delay 56
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_WalkInPlaceFasterRight
	goto PresentTown_EventScript_PeaceRangerCutscene
	end

PresentTown_EventScript_CatchPeaceRangerAttention2::
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceLeft
	playse SE_PIN
	applymovement LOCALID_PRESENT_PEACE_RANGER, PresentTown_Movement_PeaceRangerEmoteTurn
	waitmovement 0
	delay 56
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_WalkRight
	waitmovement 0
	goto PresentTown_EventScript_PeaceRangerCutscene
	end

PresentTown_EventScript_CatchPeaceRangerAttention3::
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceLeft
	playse SE_PIN
	applymovement LOCALID_PRESENT_PEACE_RANGER, PresentTown_Movement_PeaceRangerEmoteTurn
	waitmovement 0
	delay 56
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_WalkRight2
	waitmovement 0
	goto PresentTown_EventScript_PeaceRangerCutscene
	end

PresentTown_EventScript_PeaceRangerCutscene::
	msgbox PresentTown_Text_PeaceRangerAlert, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox PresentTown_Text_LookerImHereToHelpFind, MSGBOX_DEFAULT
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_WalkInPlaceFasterRight
	msgbox PresentTown_Text_PeaceRangerWeCouldAlwaysUseMoreHands, MSGBOX_DEFAULT
	playse SE_SELECT
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_FaceUp
	msgbox PresentTown_Text_PeaceRangerUpThatWay, MSGBOX_DEFAULT
	playse SE_SELECT
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_FaceRight
	msgbox PresentTown_Text_PeaceRangerAsAResult, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox PresentTown_Text_LookerUnderstood, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkInPlaceFasterLeft
	msgbox PresentTown_Text_AnabelTheresNoTimeToLose, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement LOCALID_PRESENT_PEACE_RANGER, PresentTown_Movement_RunIntoForest
	applymovement LOCALID_PLAYER, PresentTown_Movement_RunIntoForest
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, PresentTown_Movement_RunIntoForest
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_PRESENT_PEACE_RANGER
	removeobject LOCALID_PLAYER
	removeobject OBJ_EVENT_ID_NPC_FOLLOWER
	destroyfollowernpc
	setvar VAR_CUTSCENE_STATE, 3
	setflag FLAG_SYS_PREVENT_MAP_FADE
	warp MAP_CUTSCENE_FOREST, 10, 17
	releaseall
	end

PresentTown_EventScript_LookerTalkNorth::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

PresentTown_EventScript_LookerTalkWest::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

PresentTown_EventScript_RangerTalkEast::
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_WalkInPlaceFasterRight
	return

PresentTown_EventScript_RangerTalkSouth::
	applymovement LOCALID_PRESENT_PEACE_RANGER, Common_Movement_WalkInPlaceFasterDown
	return

PresentTown_Movement_RunIntoForest:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PresentTown_Movement_RunIntoForestLong:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PresentTown_Movement_PeaceRangerEmoteTurn:
	emote_exclamation_mark
	face_right
	step_end

PresentTown_Text_PeaceRangerAlert:
	.string "Ranger: This way is off-limits!\n"
	.string "We're currently conducting a search-\l"
	.string "and-rescue mission for a lost child!$"

PresentTown_Text_LookerImHereToHelpFind:
	.string "Looker: I'm Looker with the police.\n"
	.string "I'm here to help find her.$"

PresentTown_Text_PeaceRangerWeCouldAlwaysUseMoreHands:
	.string "Ranger: Oh, so you're the person City\n"
	.string "Hall just called me to look out for.\p"
	.string "Fantastic! We've been short on staff,\n"
	.string "the help is really appreciated.$"

PresentTown_Text_PeaceRangerUpThatWay:
	.string "Up that way is the Shrine of Peace.\p"
	.string "It's been abandoned for a while, so\n"
	.string "there's no set path we can explore that\l"
	.string " the lost child might've gone down.$"

PresentTown_Text_PeaceRangerAsAResult:
	.string "As a result, we'll need to split up\n"
	.string "halfway through the forest to try to\l"
	.string "find her on one of the public trails.\p"
	.string "Does that sound like a plan?$"

PresentTown_Text_LookerUnderstood:
	.string "Looker: Understood.$"

PresentTown_Text_AnabelTheresNoTimeToLose:
	.string "Anabel: Let's get searching then.\n"
	.string "There's no time to lose!$"

PresentTown_Sign_AquaCorpHQ::
	msgbox PresentTown_Text_AquaCorpSign, MSGBOX_SIGN
	end

PresentTown_Text_ProsperityOhNoIWasSupposedTo:
	.string "Oh no!\p"
	.string "I was supposed to be stationed here\n"
	.string "earlier, but I overslept my shift!\p"
	.string "Now I have to make up my hours\n"
	.string "standing in this crummy rain…$"

PresentTown_Text_LookerNoBusinessInTheForest:
	.string "I have no business in the forest!\n"
	.string "I need to find Team Aqua!$"

PresentTown_Text_LookerNoBusinessInTheForest2:
	.string "I have no business in the forest!\n"
	.string "I need to find Anabel!$"

PresentTown_Text_ProsperityRangerHey:
	.string "Ranger: Hey, this way is off-limits!\p"
	.string "It's dangerous to go out there with\n"
	.string "the wild Pokémon acting so hostile!$"

PresentTown_Text_LookerSorry:
	.string "Looker: Sorry!$"

PresentTown_Text_AquaCorpSign:
	.string "AquaCorp\n"
	.string "Headquarters$"

PresentTown_Text_LookerOuch:
	.string "Looker: Ouch!$"

PresentTown_Text_AnabelLookerGreet:
	.string "Anabel: Mr. Looker.\p"
	.string "Looker: Ms. Anabel.$"

PresentTown_Text_AnabelDidYouGetTheChance:
	.string "Anabel: Did you get the chance\n"
	.string "to speak with the new leader\l"
	.string "of Team Aqua?$"

PresentTown_Text_LookerObstinate:
	.string "Looker: Yes, Matt was rather\n"
	.string "obstinate…\p"
	.string "But I did not pick up on anything\n"
	.string "peculiar from their new operation.$"

PresentTown_Text_AnabelUnderstood:
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
	.string "Looker: That's odd…\p"
	.string "Are those…\p"
	.string "Storm clouds?$"

PresentTown_Text_AnabelWhatTheHeck:
	.string "Anabel: What the heck!? Hurricane\n"
	.string "season isn't for another two months!\p"
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

PresentTown_Text_MattWhoAreYou:
	.string "Huh? Who are you?$"

PresentTown_Text_LookerMyNameIs:
	.string "Looker: My name…\n"
	.string "is Looker.\p"
	.string "I am with the International Police,\n"
	.string "here to ensure nothing shady is going\l"
	.string "with Team Aqua's new operation…$"

PresentTown_Text_MattSeriously:
	.string "Matt: Ugh, seriously?\p"
	.string "We've told every officer whose\n"
	.string "hounded us the past three months,\l"
	.string "we're REFORMED. Got it?\p"
	.string "Now scram!$"

PresentTown_Text_LookerIWillNotJustScram:
	.string "Looker: I will not scram!\n"
	.string "I am on official business!\p"
	.string "If you would like, we can schedule\n"
	.string "an audit of the facility…$"

PresentTown_Text_MattScrewOff:
	.string "Matt: Oh, screw off!$"

PresentTown_Text_AquaMemberFWait:
	.string "Grunt: Wait!$"

PresentTown_Text_AquaMemberFTalkingToMatt:
	.string "So about the operation at\n"
	.string "the east shrine…$"

PresentTown_Text_AquaMemberFNowHesMad:
	.string "Now you've done it!\p"
	.string "It'll take hours to get him\n"
	.string "to calm down…$"