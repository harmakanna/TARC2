ShrineOfPeacePresent_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShrineOfPeacePresent_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, ShrineOfPeacePresent_OnLoad
    map_script MAP_SCRIPT_ON_FRAME_TABLE, ShrineOfPeacePresent_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, ShrineOfPeacePresent_OnResume
	.byte 0

ShrineOfPeacePresent_OnLoad:
	call_if_eq VAR_TRIGGER_CUTSCENE_FOREST, 1, ShrineOfPeacePresent_EventScript_UnsetPresentTownWarpTiles
	end

ShrineOfPeacePresent_EventScript_UnsetPresentTownWarpTiles::
	setmetatile 13, 21, 0x21B, FALSE
	setmetatile 14, 21, 0x21C, FALSE
	setmetatile 15, 21, 0x21D, FALSE
	return

ShrineOfPeacePresent_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetStormWeather
	call_if_eq VAR_CUTSCENE_STATE, 5, ShrineOfPeacePresent_EventScript_CelebiEncounterSetup
	end

ShrineOfPeacePresent_EventScript_CelebiEncounterSetup::
	setobjectxyperm LOCALID_SHRINE_PRESENT_CELEBI, 14, 21
	setflag FLAG_SYS_PREVENT_MAP_FADE
	return

ShrineOfPeacePresent_OnFrame:
    map_script_2 VAR_CUTSCENE_STATE, 5, ShrineOfPeacePresent_EventScript_CelebiEncounter
	map_script_2 VAR_CUTSCENE_STATE, 12, ShrineOfPeacePresent_EventScript_MainGameStart
	map_script_2 VAR_CATCH_GENIES_QUEST, 1, ShrineOfPeacePresent_EventScript_StartGeniesQuest
    .2byte 0

ShrineOfPeacePresent_EventScript_StartGeniesQuest::
	lock
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	delay 80
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	delay 80
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft2
	delay 120
	speakername Name_Looker
	msgbox ShrineOfPeacePresent_Text_LookerStartGeniesQuest
	startquest QUEST_CATCH_GENIES
	setvar VAR_CATCH_GENIES_QUEST, 2
	release
	end

ShrineOfPeacePresent_EventScript_MainGameStart::
	lock
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, ShrineOfPeacePresent_Text_MainGameStart
	startquest QUEST_INTERROGATE_MATT
	setflag FLAG_SYS_MAIN_GAME_START
	setflag FLAG_SYS_QUEST_MENU_GET
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	setvar VAR_CUTSCENE_STATE, 13
	release
	end

ShrineOfPeacePresent_EventScript_CelebiEncounter::
	lockall
	delay 80
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	special SpawnCameraObject
	setvar VAR_0x8004, 14  @ x
	setvar VAR_0x8005, 22  @ y
	special TeleportCamera
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_FROM_BLACK
	delay 10
	applymovement LOCALID_PLAYER, ShrineOfPeacePresent_Movement_RunToCenterCamera1
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, ShrineOfPeacePresent_Movement_RunToCenterCamera2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_SHRINE_PEACE_PRESENT_ANABEL, DIR_WEST, Name_Anabel, ShrineOfPeacePresent_Text_AnabelAlmostToTheShrine
	closemessage
	applymovement LOCALID_CAMERA, ShrineOfPeacePresent_Movement_CameraTrailLooker
	applymovement LOCALID_PLAYER, ShrineOfPeacePresent_Movement_LookerRunToShrine
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, ShrineOfPeacePresent_Movement_AnabelRunToShrine
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceUpExclamationMark
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, Common_Movement_FaceUpExclamationMark
	delay 48
	speakername Name_Looker
	msgbox ShrineOfPeacePresent_Text_LookerLookUpAhead, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SHRINE_OF_PEACE_PRESENT_WILD_MONS
	@ addobject LOCALID_SHRINE_PEACE_PRESENT_MON1
	@ addobject LOCALID_SHRINE_PEACE_PRESENT_MON2
	@ addobject LOCALID_SHRINE_PEACE_PRESENT_MON3
	@ addobject LOCALID_SHRINE_PEACE_PRESENT_MON4
	delay 20
	applymovement LOCALID_CAMERA, ShrineOfPeacePresent_Movement_PanCameraToShrine
	waitmovement 0
	delay 40
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON1, ShrineOfPeacePresent_Movement_Mon1
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON2, ShrineOfPeacePresent_Movement_Mon2
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON3, ShrineOfPeacePresent_Movement_Mon3
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON4, ShrineOfPeacePresent_Movement_Mon4
	delay 20
	applymovement LOCALID_CAMERA, ShrineOfPeacePresent_Movement_PanCameraToLooker
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_SHRINE_PEACE_PRESENT_ANABEL, DIR_WEST, Name_Anabel, ShrineOfPeacePresent_Text_AnabelItsTooDangerous
	playse SE_PIN
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, Common_Movement_FaceDownExclamationMark
	delay 48
	playse SE_SELECT
	speakername Name_Anabel
	msgbox ShrineOfPeacePresent_Text_AnabelOhNo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON5, ShrineOfPeacePresent_Movement_Mon57
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON6, ShrineOfPeacePresent_Movement_Mon6
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON7, ShrineOfPeacePresent_Movement_Mon57
	waitmovement 0
	delay 20
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
	delay 40
	clearflag FLAG_HIDE_SHRINE_PEACE_CELEBI
	setobjectxyperm LOCALID_SHRINE_PRESENT_CELEBI, 14, 21
	addobject LOCALID_SHRINE_PRESENT_CELEBI
	speakername Name_Anabel
	msgbox ShrineOfPeacePresent_Text_AnabelWhatNow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON1, Common_Movement_WalkRight
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON2, Common_Movement_WalkRight
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON3, Common_Movement_FaceLeft
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON4, Common_Movement_WalkLeft
	waitmovement 0
	delay 20
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON5, Common_Movement_WalkUp
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON6, Common_Movement_WalkUp
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON7, Common_Movement_WalkUp
	waitmovement 0
	delay 40
	message ShrineOfPeacePresent_Text_CelebiBii1
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	waitmoncry
	delay 80
	speakername Name_Anabel
	message ShrineOfPeacePresent_Text_AnabelShoutsLooker
	applymovement LOCALID_PLAYER, Common_Movement_FaceRightExclamationMark
	playse SE_PIN
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, ShrineOfPeacePresent_Movement_TeleportAway
	waitmovement 0
	closemessage
	playse SE_WARP_IN
	removeobject LOCALID_SHRINE_PEACE_PRESENT_ANABEL
	playmoncry SPECIES_MANECTRIC, CRY_MODE_NORMAL
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON4, ShrineOfPeacePresent_Movement_Mon4Attack
	setflag FLAG_HIDE_SHRINE_PEACE_PRESENT_ANABEL
	delay 100
	speakername Name_Looker
	msgbox ShrineOfPeacePresent_Text_LookerAnabel, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	delay 48
	playse SE_SELECT
	speakername Name_Looker
	msgbox ShrineOfPeacePresent_Text_LookerHuh, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON1, Common_Movement_WalkRight
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON2, Common_Movement_WalkRight
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON3, Common_Movement_WalkLeft
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON4, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON2, Common_Movement_FaceDown
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON3, Common_Movement_FaceDown
	delay 40
	applymovement LOCALID_CAMERA, ShrineOfPeacePresent_Movement_CameraPanToCelebi
	applymovement LOCALID_SHRINE_PRESENT_CELEBI, ShrineOfPeacePresent_Movement_CelebiEnterShot
	waitmovement 0
	setobjectmovementtype LOCALID_SHRINE_PRESENT_CELEBI, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP
	delay 100
	message ShrineOfPeacePresent_Text_CelebiBii2
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	waitmoncry
	delay 40
	applymovement LOCALID_PLAYER, ShrineOfPeacePresent_Movement_TeleportAwayLooker
	delay 40
	closemessage
	playse SE_WARP_IN
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON5, Common_Movement_WalkFastUp
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON6, Common_Movement_WalkFastUp
	applymovement LOCALID_SHRINE_PEACE_PRESENT_MON7, Common_Movement_WalkFastUp
	delay 20
	playmoncry SPECIES_MANECTRIC, CRY_MODE_NORMAL
	delay 10
	fadescreen FADE_TO_BLACK
	clearflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	setflag FLAG_HIDE_SHRINE_OF_PEACE_PRESENT_WILD_MONS
	setflag FLAG_HIDE_SHRINE_PEACE_CELEBI
	setrespawn HEAL_LOCATION_PAST
	warpsilent MAP_SHRINE_OF_PEACE_PAST, 14, 13
	end

ShrineOfPeacePresent_Movement_CameraPanToCelebi:
	walk_down
	walk_down
	step_end

ShrineOfPeacePresent_Movement_CelebiEnterShot:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

ShrineOfPeacePresent_Movement_TeleportAway:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	step_end

ShrineOfPeacePresent_Movement_TeleportAwayLooker:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	step_end

ShrineOfPeacePresent_Movement_Mon4Attack:
	lock_facing_direction
	walk_faster_left
	walk_right
	step_end

ShrineOfPeacePresent_Movement_Mon1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end

ShrineOfPeacePresent_Movement_Mon2:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ShrineOfPeacePresent_Movement_Mon3:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ShrineOfPeacePresent_Movement_Mon4:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

ShrineOfPeacePresent_Movement_Mon57:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ShrineOfPeacePresent_Movement_Mon6:
	delay_8
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ShrineOfPeacePresent_Movement_RunToCenterCamera1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ShrineOfPeacePresent_Movement_RunToCenterCamera2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ShrineOfPeacePresent_Movement_CameraTrailLooker:
    delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ShrineOfPeacePresent_Movement_LookerRunToShrine:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
	
ShrineOfPeacePresent_Movement_AnabelRunToShrine:
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ShrineOfPeacePresent_Movement_PanCameraToShrine:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ShrineOfPeacePresent_Movement_PanCameraToLooker:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


ShrineOfPeacePresent_OnResume:
	special HealPlayerParty
	end
	
ShrineOfPeacePresent_EventScript_Celebi::
	lockall
	faceplayer
	speakername Name_Celebi
	msgbox ShrineOfPeacePresent_Text_Celebi, MSGBOX_DEFAULT
	speakername NULL
	msgbox ShrineOfPeacePresent_Text_CelebiWarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShrineOfPeacePresent_EventScript_HandleWarpEvents
	releaseall
	end

ShrineOfPeacePresent_EventScript_HandleWarpEvents::
	setrespawn HEAL_LOCATION_PAST
	call ShrineOfPeacePresent_EventScript_ResetWarpEvents
	returnqueststate QUEST_GET_INTO_THE_GROOVE
	call_if_eq VAR_RESULT, 2, ShrineOfPeacePresent_EventScript_HandlePastLisiaSpawn
	goto ShrineOfPeacePresent_EventScript_CelebiWarp
	end

ShrineOfPeacePresent_EventScript_ResetWarpEvents::
	clearflag FLAG_SYS_WEATHER_CTRL
	return

ShrineOfPeacePresent_EventScript_HandlePastLisiaSpawn::
	call_if_set FLAG_HIDE_CAFE_IDOL_LISIA, ShrineOfPeacePast_EventScript_TrySpawnPastLisia
	return

ShrineOfPeacePast_EventScript_TrySpawnPastLisia::
	randompercentage 50
	call_if_eq VAR_RESULT, TRUE, ShrineOfPeacePast_EventScript_SpawnPastLisia
	return

ShrineOfPeacePast_EventScript_SpawnPastLisia::
	clearflag FLAG_HIDE_PAST_LISIA
	return
	
ShrineOfPeacePresent_EventScript_CelebiWarp::
	warpteleport MAP_SHRINE_OF_PEACE_PAST, 14, 9
	waitstate
	releaseall
	end

ShrineOfPeacePresent_EventScript_WarpToCutsceneForest::
	lockall
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	warp MAP_CUTSCENE_FOREST, 10, 4
	waitstate
	releaseall
	end

ShrineOfPeacePresent_Text_MainGameStart:
	.string "Alright, first things first.\p"
	.string "I am highly suspicious of Team Aqua\n"
	.string "following the new info.\p"
	.string "However, if they don't cooperate, they\n"
	.string "will surely be tough to take down alone.\p"
	.string "I wonder if I could do some favors and\n"
	.string "get some help in my investigation…$"

ShrineOfPeacePresent_Text_Celebi:
	.string "Biii?$"

ShrineOfPeacePresent_Text_CelebiWarp:
	.string "Celebi is looking at you\n"
	.string "expectantly…\p"
	.string "Warp to the past?$"

ShrineOfPeacePresent_Text_LookerHuh:
	.string "Huh…?\p"
	.string "What's that…?$"

ShrineOfPeacePresent_Text_AnabelAlmostToTheShrine:
	.string "I see a clearing up ahead!\n"
	.string "I think we're almost to the shrine!$"

ShrineOfPeacePresent_Text_LookerLookUpAhead:
	.string "Anabel, look up ahead!$"

ShrineOfPeacePresent_Text_AnabelItsTooDangerous:
	.string "It's an ambush!\p"
	.string "Looker, it's too dangerous! We won't\n"
	.string "save Estella like this ourselves!\p"
	.string "We NEED to turn back!$"

ShrineOfPeacePresent_Text_AnabelOhNo:
	.string "Oh no…$"

ShrineOfPeacePresent_Text_AnabelWhatNow:
	.string "What do we do now? There's just\n"
	.string "too many of them to fight!$"

ShrineOfPeacePresent_Text_CelebiBii1:
	.string "Biii!$"

ShrineOfPeacePresent_Text_CelebiBii2:
	.string "Biiiiiii!$"

ShrineOfPeacePresent_Text_AnabelShoutsLooker:
	.string "Looker, help!$"

ShrineOfPeacePresent_Text_LookerAnabel:
	.string "What?\p"
	.string "Anabel…?$"	

ShrineOfPeacePresent_Text_LookerStartGeniesQuest:
	.string "Huh…?\p"
	.string "I thought I quelled the spirits\n"
	.string "already…\p"
	.string "Why is it back to storming…?$"
