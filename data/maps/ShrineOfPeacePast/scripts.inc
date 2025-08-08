ShrineOfPeacePast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShrineOfPeacePast_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, ShrineOfPeacePast_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, ShrineOfPeacePast_OnResume
	.byte 0

ShrineOfPeacePast_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 3, ShrineOfPeacePast_EventScript_ShrineFirstWarpSetup
	end

ShrineOfPeacePast_EventScript_ShrineFirstWarpSetup::
	setflag FLAG_SYS_PREVENT_MAP_FADE
	return

ShrineOfPeacePast_OnFrame:
    map_script_2 VAR_CUTSCENE_STATE, 3, ShrineOfPeacePast_EventScript_FirstWarp
    .2byte 0

ShrineOfPeacePast_EventScript_FirstWarp::
	lockall
	delay 100
	msgbox ShrineOfPeacePast_Text_Dots, MSGBOX_DEFAULT
	closemessage
	delay 100
	msgbox ShrineOfPeacePast_Text_Dots, MSGBOX_DEFAULT
	closemessage
	delay 100
	msgbox ShrineOfPeacePast_Text_LookerUrgh, MSGBOX_DEFAULT
	closemessage
	delay 80
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_FROM_BLACK
	delay 60
	applymovement LOCALID_PLAYER, ShrineOfPeacePast_Movement_LookerLooksAround
	waitmovement 0
	speakername Name_Looker
	msgbox ShrineOfPeacePast_Text_LookerWhatHappened, MSGBOX_DEFAULT
	closemessage
	delay 60
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceDownExclamationMark
	delay 48
	speakername Name_Looker
	msgbox ShrineOfPeacePast_Text_LookerAnabel, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_B_DASH
	setvar VAR_CUTSCENE_STATE, 4
	releaseall
	end

 ShrineOfPeacePast_Movement_LookerLooksAround:
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
	step_end

ShrineOfPeacePast_OnResume:
	special HealPlayerParty
	end
	
ShrineOfPeacePast_EventScript_WarpToForestL::
	lockall
	speakername Name_Looker
	msgbox ShrineOfPeacePast_Text_LookerISeeFootsteps, MSGBOX_DEFAULT
	closemessage
	warp MAP_CUTSCENE_FOREST_PAST, 9, 6
	delay 48
	end

ShrineOfPeacePast_EventScript_WarpToForestM::
	lockall
	speakername Name_Looker
	msgbox ShrineOfPeacePast_Text_LookerISeeFootsteps, MSGBOX_DEFAULT
	closemessage
	warp MAP_CUTSCENE_FOREST_PAST, 10, 6
	delay 48
	end

ShrineOfPeacePast_EventScript_WarpToForestR::
	lockall
	speakername Name_Looker
	msgbox ShrineOfPeacePast_Text_LookerISeeFootsteps, MSGBOX_DEFAULT
	closemessage
	warp MAP_CUTSCENE_FOREST_PAST, 11, 6
	delay 48
	end

ShrineOfPeacePast_EventScript_Celebi::
	lockall
	faceplayer
	goto_if_unset FLAG_WARPED_WITH_CELEBI, ShrineOfPeacePast_EventScript_CelebiFirstWarp
	speakername Name_Celebi
	msgbox ShrineOfPeacePast_Text_Celebi
	speakername NULL
	msgbox ShrineOfPeacePast_Text_CelebiWarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShrineOfPeacePast_EventScript_HandleWarpEvents
	releaseall
	end

ShrineOfPeacePast_EventScript_CelebiFirstWarp::
	msgbox ShrineOfPeacePast_Text_CelebiFirstWarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShrineOfPeacePast_EventScript_HandleWarpEvents
	releaseall
	end

ShrineOfPeacePast_EventScript_HandleWarpEvents::
	setrespawn HEAL_LOCATION_PRESENT
	call_if_set FLAG_DEFEATED_SHRINE_GENIES, ShrineOfPeacePast_EventScript_HandlePresentGenieSpawns
	goto ShrineOfPeacePast_EventScript_CelebiWarp
	end

ShrineOfPeacePast_EventScript_HandlePresentGenieSpawns::
	clearflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_HIDE_CITY_TORNADUS
	setflag FLAG_HIDE_CITY_THUNDURUS
	randompercentage 4
	call_if_eq VAR_RESULT, TRUE, ShrineOfPeacePast_EventScript_TrySpawnPresentGenies
	return

ShrineOfPeacePast_EventScript_TrySpawnPresentGenies::
	randomelement SPECIES_TORNADUS, SPECIES_THUNDURUS
	call_if_eq VAR_RESULT, SPECIES_TORNADUS, ShrineOfPeacePast_EventScript_TrySpawnTornadus
	call_if_eq VAR_RESULT, SPECIES_THUNDURUS, ShrineOfPeacePast_EventScript_TrySpawnThundurus
	return

ShrineOfPeacePast_EventScript_TrySpawnTornadus::
	call_if_unset FLAG_CAUGHT_TORNADUS, ShrineOfPeacePast_EventScript_SpawnTornadus
	return

ShrineOfPeacePast_EventScript_TrySpawnThundurus::
	call_if_unset FLAG_CAUGHT_THUNDURUS, ShrineOfPeacePast_EventScript_SpawnThundurus
	return

ShrineOfPeacePast_EventScript_SpawnTornadus::
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_HIDE_OUTSIDE_NPCS
	clearflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
	clearflag FLAG_HIDE_CITY_TORNADUS
	return

ShrineOfPeacePast_EventScript_SpawnThundurus::
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_HIDE_OUTSIDE_NPCS
	clearflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
	clearflag FLAG_HIDE_CITY_THUNDURUS
	return

ShrineOfPeacePast_EventScript_EndSpawnGenie::
	return

ShrineOfPeacePast_EventScript_CelebiWarp::
	setflag FLAG_WARPED_WITH_CELEBI
	warpteleport MAP_SHRINE_OF_PEACE_PRESENT, 14, 9
	waitstate
	releaseall
	end

ShrineOfPeacePast_Text_CelebiFirstWarp:
	.string "Celebi is looking at you\n"
	.string "expectantly…\p"
	.string "Reach out your hand?$"

ShrineOfPeacePast_Text_Celebi:
	.string "Biii?$"

ShrineOfPeacePast_Text_CelebiWarp:
	.string "Celebi is looking at you\n"
	.string "expectantly…\p"
	.string "Warp to the present?$"
	
ShrineOfPeacePast_Text_LookerWhatHappened:
	.string "What happened…?\p"
	.string "Everything hurts…\p"
	.string "It seems like the storm…\p"
	.string "Is over?\p"
	.string "Was I dreaming?$"

ShrineOfPeacePast_Text_LookerAnabel:
	.string "Anabel!\p"
	.string "I need to find Anabel!\p"
	.string "Did she escape into the forest…?$"

ShrineOfPeacePast_Text_LookerISeeFootsteps:
	.string "I think these look like her\n"
	.string "footsteps…?$"

ShrineOfPeacePast_Text_LookerUrgh:
	.string "… … …\n"
	.string "… … …\p"
	.string "Urgh… … …$"
	
ShrineOfPeacePast_Text_Dots:
	.string "… … …\n"
	.string "… … …$"