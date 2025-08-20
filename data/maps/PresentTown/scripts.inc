PresentTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PresentTown_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PresentTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PresentTown_OnResume
@	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PresentTown_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PresentTown_OnFrame
	.byte 0
	
@ Comment out FLAG_SYS_MAIN_GAME_START_SCRIPT_DEBUG line to test intro
PresentTown_OnLoad:
	call_if_eq VAR_CUTSCENE_STATE, 4, PresentTown_EventScript_ChangeAnabelFollowerText
	@call_if_unset FLAG_SYS_MAIN_GAME_START_SCRIPT_DEBUG, PresentTown_EventScript_DebugMainGameStart
	call_if_set FLAG_LOCK_CITY_DOORS, PresentTown_EventScript_LockCityDoors
	end

PresentTown_EventScript_ChangeAnabelFollowerText::
	setflag FLAG_STEPPED_OUT_OF_CITY_HALL
	return

PresentTown_EventScript_DebugMainGameStart::
	setvar VAR_CUTSCENE_STATE, 13
	setvar VAR_PORTO_BELLA_CITY_STATE, 3
	setvar VAR_QUEUE_GENIE_FIGHT, 1
	setvar VAR_PRESENT_GYM_STATE, 1
	setflag FLAG_SYS_MAIN_GAME_START_SCRIPT_DEBUG
	setflag FLAG_SYS_MAIN_GAME_START
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_TALKED_TO_MATT_OUTSIDE
	setflag FLAG_MET_CELEBI
	setflag FLAG_HIDE_OUTSIDE_NPCS
	setflag FLAG_HIDE_TORNADUS_NPCS
	clearflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
	clearflag FLAG_HIDE_SHRINE_PROSPERITY_RANGER
	setflag FLAG_HIDE_MATT_OUTSIDE
	setflag FLAG_HIDE_AQUA_GRUNT_OUTSIDE
	setflag FLAG_HIDE_ANABEL_PRESENTTOWN
	setflag FLAG_HIDE_ANABEL_CITYHALL
	clearflag FLAG_HIDE_CITYHALL_1F_MAYOR
	setflag FLAG_ACCEPTED_SCARED_DADS_REQUEST
	setflag FLAG_STEPPED_OUT_OF_CITY_HALL
	setflag FLAG_HIDE_SHRINE_PEACE_PRESENT_ANABEL
	setflag FLAG_HIDE_PAST_TOWN_HALL_ANABEL
	setflag FLAG_HIDE_PAST_TOWN_HALL_ESTELLA
	setflag FLAG_FOUGHT_LASS
	setflag FLAG_HIDE_SHRINE_PROSPERITY_PAST_ANABEL
	setflag FLAG_HIDE_CITYHALL_1F_EMPLOYEE
	clearflag FLAG_HIDE_SHRINE_PEACE_CELEBI
	clearflag FLAG_HIDE_CITYHALL_2F_RANGER_HEADRANGER
	givemonwithot OT_LOOKER_GROWLITHE
	givemonwithot OT_LOOKER_TOXICROAK
	givemonwithot OT_EMMA_GUMSHOOS
	questmenu QUEST_MENU_SET_REWARD, QUEST_SAVE_ESTELLA
	startquest QUEST_INTERROGATE_MATT
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
	call_if_unset FLAG_SYS_WEATHER_CTRL, PresentTown_EventScript_ClearTornadusNPCFlag
	call_if_set FLAG_TALKED_TO_MATT_OUTSIDE, PresentTown_EventScript_AquaMemberFPositioning
	@call_if_eq VAR_PORTO_BELLA_CITY_STATE, 1, PresentTown_EventScript_PrepareAnabelForCutscene
	end

PresentTown_EventScript_ClearTornadusNPCFlag::
	clearflag FLAG_HIDE_TORNADUS_NPCS
	return

PresentTown_EventScript_AquaMemberFPositioning::
	setobjectxyperm LOCALID_PRESENTTOWN_GRUNT, 15, 35
	setobjectmovementtype LOCALID_PRESENTTOWN_GRUNT, MOVEMENT_TYPE_FACE_UP
	return
	
PresentTown_EventScript_PrepareAnabelForCutscene::
	setobjectxyperm LOCALID_PRESENTTOWN_ANABEL, 37, 28
	return
	
PresentTown_OnFrame:
	map_script_2 VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 1, PresentTown_EventScript_LookerThinkingScenes
	map_script_2 VAR_CATCH_GENIES_QUEST, 4, PresentTown_EventScript_FinishGeniesQuest
	.2byte 0

PresentTown_EventScript_FinishGeniesQuest::
	lock
	delay 30
	speakername Name_Looker
	msgbox PresentTown_Text_LookerTheSpiritsAreCaught, MSGBOX_DEFAULT
	completequest QUEST_CATCH_GENIES
	addvar VAR_CATCH_GENIES_QUEST, 1
	release
	end

PresentTown_EventScript_LookerThinkingScenes::
	call_if_set FLAG_PLAY_LOOKER_AQUA_ON_TRANSITION, PresentTown_EventScript_LookerThinkingAqua
	call_if_set FLAG_PLAY_LOOKER_GYM_ON_TRANSITION, PresentTown_EventScript_LookerThinkingGym
	call_if_set FLAG_PLAY_LOOKER_ESTELLA_ON_TRANSITION, PresentTown_EventScript_LookerThinkingEstella
	call_if_set FLAG_PLAY_LOOKER_RANGER_ON_TRANSITION, PresentTown_EventScript_LookerThinkingRanger
	call_if_eq VAR_MAIN_QUEST_STATE, 4, PresentTown_EventScript_LookerThinkingIGotIt
	call_if_eq VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 1, PresentTown_EventScript_EndLookerThinking
	end

PresentTown_EventScript_LookerThinkingAqua::
	lock
	playbgm MUS_PL_LOOKER, FALSE
	addvar VAR_MAIN_QUEST_STATE, 1
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, PresentTown_Text_LookerThinkingAqua
	return

PresentTown_EventScript_LookerThinkingGym::
	lock
	playbgm MUS_PL_LOOKER, FALSE
	addvar VAR_MAIN_QUEST_STATE, 1
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, PresentTown_Text_LookerThinkingGym
	return

PresentTown_EventScript_LookerThinkingEstella::
	lock
	playbgm MUS_PL_LOOKER, FALSE
	addvar VAR_MAIN_QUEST_STATE, 1
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, PresentTown_Text_LookerThinkingEstella
	return
	
PresentTown_EventScript_LookerThinkingRanger::
	lock
	playbgm MUS_PL_LOOKER, FALSE
	addvar VAR_MAIN_QUEST_STATE, 1
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, PresentTown_Text_LookerThinkingRanger
	return

PresentTown_EventScript_LookerThinkingIGotIt::
	closemessage
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 50
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, PresentTown_Text_LookerIGotIt
	startquest QUEST_FIND_THE_CULPRIT
	return

PresentTown_EventScript_EndLookerThinking::
	closemessage
	fadeoutbgm 0
	call_if_set FLAG_SYS_WEATHER_CTRL, PresentTown_EventScript_PlayNoMusic
	call_if_unset FLAG_SYS_WEATHER_CTRL, PresentTown_EventScript_PlayDefaultMusic
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	clearflag FLAG_PLAY_LOOKER_AQUA_ON_TRANSITION
	clearflag FLAG_PLAY_LOOKER_GYM_ON_TRANSITION
	clearflag FLAG_PLAY_LOOKER_ESTELLA_ON_TRANSITION
	clearflag FLAG_PLAY_LOOKER_RANGER_ON_TRANSITION
	setvar VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 0
	release
	end

PresentTown_EventScript_PlayNoMusic:
	playbgm MUS_NONE, TRUE
	return

PresentTown_EventScript_PlayDefaultMusic:
	playbgm MUS_DP_SUNYSHORE_DAY, TRUE
	return 

PresentTown_OnResume:
	special HealPlayerParty
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PresentTown_EventScript_TryRemoveTornadus
	end
	
PresentTown_EventScript_TryRemoveTornadus::
	specialvar VAR_RESULT, GetBattleOutcome
	call_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PresentTown_EventScript_RemoveTornadus
	return

PresentTown_EventScript_RemoveTornadus::
	setflag FLAG_CAUGHT_TORNADUS
	setweather WEATHER_SUNNY
	doweather
	call Common_EventScript_MoveInsideNPCsOutside
	removeobject LOCALID_CITY_TORNADUS
	addvar VAR_CATCH_GENIES_QUEST, 1
	return

PresentTown_EventScript_StartStorm1::
	lockall
	clearflag FLAG_HIDE_PORTO_BELLA_WILD_MONS
	addobject LOCALID_PRESENTTOWN_ANABEL
	setvar VAR_0x8008, 0
	setvar VAR_FACING, DIR_EAST
	setobjectxy LOCALID_PRESENTTOWN_ANABEL, 41, 27
	goto PresentTown_EventScript_StartStorm
	end

PresentTown_EventScript_StartStorm2::
	lockall
	clearflag FLAG_HIDE_PORTO_BELLA_WILD_MONS
	addobject LOCALID_PRESENTTOWN_ANABEL
	setvar VAR_0x8008, 1
	setvar VAR_FACING, DIR_EAST
	setobjectxy LOCALID_PRESENTTOWN_ANABEL, 41, 28
	goto PresentTown_EventScript_StartStorm
	end

PresentTown_EventScript_StartStorm::
	applymovement LOCALID_PRESENTTOWN_ANABEL, PresentTown_Movement_AnabelWalkToPlayerBridge
	waitmovement 0
	call Script_GetNPCFacingDirection
	speak LOCALID_PRESENTTOWN_ANABEL, VAR_0x8005, Name_Anabel, PresentTown_Text_AnabelGreet
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Text_LookerGreet
	speak LOCALID_PRESENTTOWN_ANABEL, VAR_0x8005, Name_Anabel, PresentTown_Text_AnabelDidYouGetTheChance
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Text_LookerObstinate
	speak LOCALID_PRESENTTOWN_ANABEL, VAR_0x8005, Name_Anabel, PresentTown_Text_AnabelUnderstood
	closemessage
	playse SE_PIN
	call_if_eq VAR_0x8008, 0, PresentTown_EventScript_AnabelLookAtStormTop
	call_if_eq VAR_0x8008, 1, PresentTown_EventScript_AnabelLookAtStormBottom
	delay 100
	speakername Name_Looker
	msgbox PresentTown_Text_LookerISeeIt, MSGBOX_DEFAULT
	closemessage
	playse SE_THUNDERSTORM
	waitse
	call Common_EventScript_SetStormWeather
	doweather
	delay 120
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_PRESENTTOWN_ANABEL, DIR_WEST, Name_Anabel, PresentTown_Text_AnabelWhatTheHeck
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, PresentTown_Text_LookerThereWasOneThing
	closemessage
	setobjectxyperm LOCALID_PRESENTTOWN_WILDMON1, 24, 27
	setobjectxyperm LOCALID_PRESENTTOWN_WILDMON2, 24, 28
	setobjectxyperm LOCALID_PRESENTTOWN_WILDMON3, 23, 27
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
	speakername Name_Anabel
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
	setflag FLAG_SYS_SPAWN_INVISIBLE
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	setflag FLAG_LOCK_CITY_DOORS
	setflag FLAG_HIDE_OUTSIDE_NPCS
	setflag FLAG_HIDE_TORNADUS_NPCS
	setflag FLAG_HIDE_OUTSIDE_IDOLS
	setflag FLAG_HIDE_AQUA_GRUNT_OUTSIDE
	setflag FLAG_HIDE_ANABEL_PRESENTTOWN
	setflag FLAG_HIDE_CITYHALL_2F_RANGER_HEADRANGER
	setflag FLAG_HIDE_CITYHALL_1F_EMPLOYEE
	clearflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
	clearflag FLAG_HIDE_SHRINE_PEACE_RANGER
	clearflag FLAG_HIDE_SHRINE_PROSPERITY_RANGER
	clearflag FLAG_HIDE_CITYHALL_1F_MAYOR
	clearflag FLAG_HIDE_ANABEL_CITYHALL
	setvar VAR_PORTO_BELLA_CITY_STATE, 2
	setvar VAR_CUTSCENE_STATE, 3
	warp MAP_PRESENT_CITY_HALL_1F, 8, 8
	waitstate
	releaseall
	end

PresentTown_EventScript_AnabelLookAtStormTop::
	applymovement LOCALID_PRESENTTOWN_ANABEL, PresentTown_Movement_AnabelLookAtStorm1
	waitmovement 0
	fadenewbgm MUS_NONE
	speakername Name_Anabel
	msgbox PresentTown_Text_AnabelThatsStrange, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, PresentTown_Text_LookerWhatsWrong
	speak LOCALID_PRESENTTOWN_ANABEL, DIR_WEST, Name_Anabel, PresentTown_Text_AnabelTakeACloserLook
	closemessage
	applymovement LOCALID_PRESENTTOWN_ANABEL, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

PresentTown_EventScript_AnabelLookAtStormBottom::
	applymovement LOCALID_PRESENTTOWN_ANABEL, PresentTown_Movement_AnabelLookAtStorm2
	waitmovement 0
	fadenewbgm MUS_NONE
	speakername Name_Anabel
	msgbox PresentTown_Text_AnabelThatsStrange, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, PresentTown_Text_LookerWhatsWrong
	speak LOCALID_PRESENTTOWN_ANABEL, DIR_SOUTH, Name_Anabel, PresentTown_Text_AnabelTakeACloserLook
	closemessage
	applymovement LOCALID_PRESENTTOWN_ANABEL, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	return

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
	delay_16
	delay_16
	step_end

PresentTown_Movement_AnabelLookAtStorm2:
	face_up
	emote_question_mark
	delay_16
	delay_16
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
	step_end

PresentTown_EventScript_Matt::
	lockall
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PRESENTTOWN_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_Delay32
	waitmovement 0
	speakername Name_Matt
	msgbox PresentTown_Text_MattTalkingToGrunt, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	faceplayer
	applymovement LOCALID_PRESENTTOWN_MATT, Common_Movement_ExclamationMark
	delay 48
	call Script_GetNPCFacingDirection
	speak LOCALID_PRESENTTOWN_MATT, VAR_0x8005, Name_Matt, PresentTown_Text_MattWhoAreYou
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Text_LookerMyNameIs
	speak LOCALID_PRESENTTOWN_MATT, VAR_0x8005, Name_Matt, PresentTown_Text_MattSeriously
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Text_LookerIWillNotJustScram
	speak LOCALID_PRESENTTOWN_MATT, VAR_0x8005, Name_Matt, PresentTown_Text_MattScrewOff
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, PresentTown_EventScript_MattAttackSide
	goto PresentTown_EventScript_MattAttackDown
	end

PresentTown_EventScript_MattAttackDown::
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

PresentTown_EventScript_MattAttackSide::
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
	speakername Name_Aqua_Grunt
	message PresentTown_Text_AquaMemberFWait
	waitmessage
	applymovement LOCALID_PRESENTTOWN_GRUNT, PresentTown_Movement_GruntFollowsMatt
	waitmovement 0
	closemessage
	delay 80
	speak LOCALID_PRESENTTOWN_GRUNT, VAR_0x8005, Name_Aqua_Grunt, PresentTown_Text_AquaMemberFNowHesMad
	setobjectxyperm LOCALID_PRESENTTOWN_GRUNT, 15, 35
	setobjectmovementtype LOCALID_PRESENTTOWN_GRUNT, MOVEMENT_TYPE_FACE_UP
	applymovement LOCALID_PRESENTTOWN_GRUNT, Common_Movement_FaceUp
	waitmovement 0
	setflag FLAG_TALKED_TO_MATT_OUTSIDE
	clearflag FLAG_HIDE_ANABEL_PRESENTTOWN
	setvar VAR_PORTO_BELLA_CITY_STATE, 1
	removeobject LOCALID_PRESENTTOWN_MATT
	@setobjectxyperm LOCALID_PRESENTTOWN_ANABEL, 37, 28
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
	speakername Name_Looker
	msgbox PresentTown_Text_LookerNoBusinessInTheForest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end 

PresentTown_EventScript_NoBusinessInTheForest2::
	lockall
	speakername Name_Looker
	msgbox PresentTown_Text_LookerNoBusinessInTheForest2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end 

@ Intro
PresentTown_EventScript_CatchProsperityRangerAttention::
	lockall
	applymovement LOCALID_PRESENT_PROSPERITY_RANGER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceRight
	speakername Name_Ranger
	msgbox PresentTown_Text_ProsperityRangerHey, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Text_LookerSorry
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceDown
	releaseall
	end

@ Main game, blocking from going to see Tornadus
PresentTown_EventScript_CatchProsperityRangerAttention2::
	lockall
	applymovement LOCALID_PRESENT_PROSPERITY_RANGER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	msgbox PresentTown_Text_ProsperityRangerNoPassing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

PresentTown_EventScript_ProsperityRanger::
	lockall
	faceplayer
	goto_if_eq VAR_CUTSCENE_STATE, 4, PresentTown_EventScript_ProsperityRangerOhNo
	goto_if_eq VAR_QUEUE_GENIE_FIGHT, 1, PresentTown_EventScript_ProsperityRangerNoPassing
	msgbox PresentTown_Text_ProsperityRangerYouCanPass, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PresentTown_EventScript_ProsperityRangerNoPassing::
	msgbox PresentTown_Text_ProsperityRangerNoPassing, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PresentTown_EventScript_ProsperityRangerOhNo::
	msgbox PresentTown_Text_ProsperityOhNoIWasSupposedTo, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PresentTown_EventScript_PeaceRanger::
	lockall
	turnobject OBJ_EVENT_ID_NPC_FOLLOWER, DIR_NORTH
	goto PresentTown_EventScript_PeaceRangerCutscene
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
	setvar VAR_FACING, DIR_WEST
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
	setvar VAR_FACING, DIR_WEST
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
	setvar VAR_FACING, DIR_WEST
	goto PresentTown_EventScript_PeaceRangerCutscene
	end

PresentTown_EventScript_PeaceRangerCutscene::
	call Script_GetNPCFacingDirection
	speak LOCALID_PRESENT_PEACE_RANGER, VAR_0x8005, Name_Head_Ranger, PresentTown_Text_PeaceRangerAlert
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Text_LookerImHereToHelpFind
	speak LOCALID_PRESENT_PEACE_RANGER, VAR_0x8005, Name_Head_Ranger, PresentTown_Text_PeaceRangerWeCouldAlwaysUseMoreHands
	playse SE_SELECT
	speak LOCALID_PRESENT_PEACE_RANGER, DIR_NORTH, Name_Head_Ranger, PresentTown_Text_PeaceRangerUpThatWay
	playse SE_SELECT
	speak LOCALID_PRESENT_PEACE_RANGER, VAR_0x8005, Name_Head_Ranger, PresentTown_Text_PeaceRangerAsAResult
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Text_LookerUnderstood
	speak OBJ_EVENT_ID_NPC_FOLLOWER, DIR_NORTH, Name_Anabel, PresentTown_Text_AnabelTheresNoTimeToLose
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
	setvar VAR_CUTSCENE_STATE, 5
	setflag FLAG_SYS_PREVENT_MAP_FADE
	warp MAP_CUTSCENE_FOREST, 10, 17
	releaseall
	end

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

PresentTown_EventScript_Fisherman::
	lock
	faceplayer
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_HELP_FISHERMAN
	switch VAR_RESULT
	case 1, PresentTown_EventScript_FishermanUnaware
	case 2, PresentTown_EventScript_FishermanBattle
	case 3, PresentTown_EventScript_FishermanDefeated
	case 4, PresentTown_EventScript_FishermanDefeated
	releaseall
	end

PresentTown_EventScript_FishermanUnaware::
	speakername Name_Present_Fisherman
	msgbox PresentTown_Text_FishermanUnaware, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PRESENT_FISHERMAN, Common_Movement_FaceDown
	release
	end

PresentTown_EventScript_FishermanBattle::
	setflag FLAG_SYS_NO_WHITEOUT
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Text_LookerLookingForInformationOnFishing
	speak LOCALID_PRESENT_FISHERMAN, VAR_0x8005, Name_Present_Fisherman, PresentTown_Text_FishermanPreBattle
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_AlrightFine
	trainerbattle_no_intro TRAINER_PRESENT_FISHERMAN, PresentTown_Text_FishermanDefeat
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PresentTown_EventScript_FishermanLost
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PresentTown_EventScript_FishermanLost
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Text_LookerNowWillYouTellMeFishing
	speak LOCALID_PRESENT_FISHERMAN, VAR_0x8005, Name_Present_Fisherman, PresentTown_Text_FishermanPostBattle
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ThankYouForTheIntel
	closemessage
	applymovement LOCALID_PRESENT_FISHERMAN, Common_Movement_FaceDown
	clearflag FLAG_SYS_NO_WHITEOUT
	questmenu QUEST_MENU_SET_REWARD QUEST_HELP_FISHERMAN
	release
	end

PresentTown_EventScript_FishermanLost::
	speak LOCALID_PRESENT_FISHERMAN, VAR_0x8005, Name_Present_Fisherman, PresentTown_Text_FishermanYouWontLearnMySecrets
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Dots
	closemessage
	applymovement LOCALID_PRESENT_FISHERMAN, Common_Movement_FaceDown
	clearflag FLAG_SYS_NO_WHITEOUT
	release
	end
	
PresentTown_EventScript_FishermanDefeated::
	speakername Name_Present_Fisherman
	msgbox PresentTown_Text_FishermanPostQuest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PRESENT_FISHERMAN, Common_Movement_FaceDown
	release
	end

PresentTown_EventScript_Tornadus::
	lock
	faceplayer
	waitse
	setflag FLAG_SYS_NO_WHITEOUT
	playmoncry SPECIES_TORNADUS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_TORNADUS, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	clearflag FLAG_SYS_NO_WHITEOUT
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PresentTown_EventScript_DefeatedTornadus
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PresentTown_EventScript_RanFromTornadus
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PresentTown_EventScript_RanFromTornadus
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PresentTown_EventScript_RanFromTornadus
	clearflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_SUNNY
	doweather
	removeobject VAR_LAST_TALKED
	release
	end

PresentTown_EventScript_DefeatedTornadus::
	clearflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_SUNNY
	doweather
	call Common_EventScript_MoveInsideNPCsOutside
	goto Common_EventScript_RemoveStaticPokemon
	end

PresentTown_EventScript_RanFromTornadus::
	clearflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_SUNNY
	doweather
	call Common_EventScript_MoveInsideNPCsOutside
	setvar VAR_0x8004, SPECIES_TORNADUS
	goto Common_EventScript_LegendaryFlewAway
	end

PresentTown_Text_ProsperityRangerYouCanPass:
	.string "Hello! I got the call from HQ. You're\n"
	.string "free to go to the shrine as needed!$"
	
PresentTown_Text_ProsperityRangerNoPassing:
	.string "The Shrine of Prosperity is currently\n"
	.string "off-limits to all but city personnel!\p"
	.string "There is a dangerous amount of energy\n"
	.string "coming from that part of the forest!$"

PresentTown_Text_PeaceRangerAlert:
	.string "This way is off-limits!\n"
	.string "We're currently conducting a search-\l"
	.string "and-rescue mission for a lost child!$"

PresentTown_Text_LookerImHereToHelpFind:
	.string "I'm Looker with the police.\n"
	.string "I'm here to help find her.$"

PresentTown_Text_PeaceRangerWeCouldAlwaysUseMoreHands:
	.string "Oh, so you're the person City\n"
	.string "Hall just called me to look out for.\p"
	.string "Fantastic! We've been short on staff,\n"
	.string "the help is really appreciated.$"

PresentTown_Text_PeaceRangerUpThatWay:
	.string "Up that way is the Shrine of Peace.\p"
	.string "It's been abandoned for a while, so\n"
	.string "there's no set path we can explore that\l"
	.string "the lost child might've gone down.$"

PresentTown_Text_PeaceRangerAsAResult:
	.string "As a result, we'll need to split up\n"
	.string "halfway through the forest to try to\l"
	.string "find her on one of the public trails.\p"
	.string "Does that sound like a plan?$"

PresentTown_Text_LookerUnderstood:
	.string "Understood.$"

PresentTown_Text_AnabelTheresNoTimeToLose:
	.string "Let's get searching then.\n"
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
	.string "Hey, this way is off-limits!\p"
	.string "It's dangerous to go out there with\n"
	.string "the wild Pokémon acting so hostile!$"

PresentTown_Text_LookerSorry:
	.string "Sorry!$"

PresentTown_Text_AquaCorpSign:
	.string "AquaCorp\n"
	.string "Headquarters$"

PresentTown_Text_LookerOuch:
	.string "Ouch!$"

PresentTown_Text_AnabelGreet:
	.string "Mr. Looker.$"

PresentTown_Text_LookerGreet:
	.string "Ms. Anabel.$"

PresentTown_Text_AnabelDidYouGetTheChance:
	.string "Did you get the chance\n"
	.string "to speak with the new leader\l"
	.string "of Team Aqua?$"

PresentTown_Text_LookerObstinate:
	.string "Yes, Matt was rather\n"
	.string "obstinate…\p"
	.string "But I did not pick up on anything\n"
	.string "peculiar from their new operation.$"

PresentTown_Text_AnabelUnderstood:
	.string "Understood.\p"
	.string "I spoke with the mayor, and he has\n"
	.string "a vacant office in City Hall we can\l"
	.string "use while we stay in…$"

PresentTown_Text_AnabelThatsStrange:
	.string "That's strange…$"

PresentTown_Text_LookerWhatsWrong:
	.string "What seems to be the\n"
	.string "issue, Anabel?$"

PresentTown_Text_AnabelTakeACloserLook:
	.string "Take a closer look.$"

PresentTown_Text_LookerISeeIt:
	.string "That's odd…\p"
	.string "Are those…\p"
	.string "Storm clouds?$"

PresentTown_Text_AnabelWhatTheHeck:
	.string "What the heck!? Hurricane\n"
	.string "season isn't for another two months!\p"
	.string "Looker, are you positive Team Aqua's\n"
	.string "new operation is above board?$"

PresentTown_Text_LookerThereWasOneThing:
	.string "I was not given access…\n"
	.string "We will need to do a more tho-$"

PresentTown_Text_AnabelLookOut:
	.string "Shoot!\n"
	.string "Wild Pokémon are running rampant!\p"
	.string "We need to get inside, stat!$"

PresentTown_Text_MattTalkingToGrunt:
	.string "Hehehe…\p"
	.string "These experiments are going off without\n"
	.string "a hitch!\p"
	.string "With these results, we can…$"

PresentTown_Text_MattWhoAreYou:
	.string "Huh? Who are you?$"

PresentTown_Text_LookerMyNameIs:
	.string "My name…\n"
	.string "is Looker.\p"
	.string "I am with the International Police,\n"
	.string "here to ensure nothing shady is going\l"
	.string "with Team Aqua's new operation…$"

PresentTown_Text_MattSeriously:
	.string "Ugh, seriously?\p"
	.string "We've told every officer whose\n"
	.string "hounded us the past three months,\l"
	.string "we're REFORMED. Got it?\p"
	.string "Now scram!$"

PresentTown_Text_LookerIWillNotJustScram:
	.string "I will not scram!\n"
	.string "I am on official business!\p"
	.string "If you would like, we can schedule\n"
	.string "an audit of the facility…$"

PresentTown_Text_MattScrewOff:
	.string "Oh, screw off!$"

PresentTown_Text_AquaMemberFWait:
	.string "Wait!$"

PresentTown_Text_AquaMemberFTalkingToMatt:
	.string "So about the experiment on\n"
	.string "the local wildlife…$"

PresentTown_Text_AquaMemberFNowHesMad:
	.string "Now you've done it!\p"
	.string "It'll take hours to get him\n"
	.string "to calm down…$"

PresentTown_Text_LookerThinkingGym:
	.string "Hmm…\p"
	.string "So there are some pretty strong\n"
	.string "gym challengers running around\l"
	.string "the city right now…\p"
	.string "Including one strong enough to\n"
	.string "beat a former Elite Four…\p"
	.string "Hmm…$"

PresentTown_Text_LookerThinkingAqua:
	.string "Hmm…\p"
	.string "So Team Aqua did not cause\n"
	.string "Landorus to disappear…\p"
	.string "They seem to be a lot less\n"
	.string "reckless now…\p"
	.string "Hmm…$"

PresentTown_Text_LookerThinkingEstella:
	.string "Hmm…\p"
	.string "So the story of Landorus is much\n"
	.string "less well known in the present, to\l"
	.string "the point only locals know it…\p"
	.string "And outsiders are less respectful\n"
	.string "of the power of the legends…\p"
	.string "Hmm…$"

PresentTown_Text_LookerThinkingRanger:
	.string "Hmm…\p"
	.string "So there was nobody posted at the\n"
	.string "entrance to the Shrine of Prosperity\l"
	.string "due to staffing issues…\p"
	.string "And while adults are more reserved in\n"
	.string "their catching habits, children often\l"
	.string "cause trouble for the wildlife with\l"
	.string "their insane catching sprees…\p"
	.string "Hmm…$"
	
PresentTown_Text_LookerIGotIt:
	.string "I got it!\p"
	.string "One of the gym challengers, a\n"
	.string "child, MUST have captured Landorus\l"
	.string "at the shrine, not understanding\l"
	.string "the implications of their actions!\p"
	.string "I need to find which challenger\n"
	.string "caught the legendary and close this\l"
	.string "case shut!$"

PresentTown_Text_FishermanUnaware:
	.string "Man, I just cannot stop catching fish!$"

PresentTown_Text_FishermanPreBattle:
	.string "I know where the best fishing spot would\n"
	.string "be, but I won't give it up for free!\p"
	.string "If you want it, you have to beat my fish\n"
	.string "in a battle!\p"
	.string "You want a taste of their power?$"

PresentTown_Text_FishermanDefeat:
	.string "Beaten by a man with no fish…\n"
	.string "How embarrassing.$"

PresentTown_Text_FishermanPostBattle:
	.string "Fine, I'll tell…\p"
	.string "My grandpappy's great-grandpappy Tee\n"
	.string "passed down to me his knowledge of\l"
	.string "this phenomenal fishing spot.\p"
	.string "Legend has it that a great Wailord\n"
	.string "passed away in this bay before the\l"
	.string "founding of Porta Bella.\p"
	.string "This brought schools of Pokémon to the\n"
	.string "mouth of this river, which have been\l"
	.string "breeding here ever since.\p"
	.string "When it comes to fishing spots, the\n"
	.string "mouth of the river just can't be beat!$"

PresentTown_Text_FishermanPostQuest:
	.string "When it comes to fishing spots, the mouth\n"
	.string "of the river just can't be beat!$"

PresentTown_Text_LookerLookingForInformationOnFishing:
	.string "I am looking for information on the best\n"
	.string "fishing spot in Porta Bella.\p"
	.string "Would you happen to know where that\n"
	.string "might be?$"

PresentTown_Text_LookerNowWillYouTellMeFishing:
	.string "Now will you tell me, sir?$"

PresentTown_Text_FishermanYouWontLearnMySecrets:
	.string "Heh! I won't tell you any of my fishing\n"
	.string "secrets until you beat me in a battle!$"

PresentTown_Text_LookerTheSpiritsAreCaught:
	.string "There we go…\p"
	.string "I will keep the spirits contained for\n"
	.string "the duration of my stay…\p"
	.string "This should prevent them from causing\n"
	.string "any more havoc to the city…$"