ShrineOfProsperityPast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShrineOfProsperityPast_OnTransition
	.byte 0

ShrineOfProsperityPast_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 8, ShrineOfProsperityPast_EventScript_SetupMyth
	end

ShrineOfProsperityPast_EventScript_SetupMyth::
	setobjectmovementtype LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, MOVEMENT_TYPE_FACE_LEFT
	return

ShrineOfProsperityPast_EventScript_VillageOrator::
	msgbox ShrineOfProsperityPast_Text_Orator, MSGBOX_NPC
	end

ShrineOfProsperityPast_EventScript_StartLandorusMyth::
	lockall
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraUp
	waitmovement 0
	delay 60
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraDown
	waitmovement 0
	delay 40
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	goto_if_eq VAR_TEMP_1, 11, ShrineOfProsperityPast_EventScript_StartLandorusMythL
	goto_if_eq VAR_TEMP_1, 12, ShrineOfProsperityPast_EventScript_StartLandorusMythM
	goto ShrineOfProsperityPast_EventScript_StartLandorusMythR
	end

ShrineOfProsperityPast_EventScript_StartLandorusMythL::
	applymovement LOCALID_PLAYER, ShrineOfProsperityPast_Movement_WalkToOratorL
	waitmovement 0
	goto ShrineOfProsperityPast_EventScript_LandorusMyth
	end

ShrineOfProsperityPast_EventScript_StartLandorusMythM::
	applymovement LOCALID_PLAYER, ShrineOfProsperityPast_Movement_WalkToOratorM
	waitmovement 0
	goto ShrineOfProsperityPast_EventScript_LandorusMyth
	end

ShrineOfProsperityPast_EventScript_StartLandorusMythR::
	applymovement LOCALID_PLAYER, ShrineOfProsperityPast_Movement_WalkToOratorR
	waitmovement 0
	goto ShrineOfProsperityPast_EventScript_LandorusMyth
	end

ShrineOfProsperityPast_EventScript_LandorusMyth::
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, ShrineOfProsperityPast_Movement_AnabelWalkOffScreen
	waitmovement 0
	delay 40
	removeobject LOCALID_SHRINE_PROSPERITY_PAST_ANABEL
	clearflag FLAG_HIDE_SHRINE_PEACE_CELEBI
	setflag FLAG_HIDE_PAST_TOWN_HALL_ESTELLA
	setflag FLAG_SYS_MAIN_GAME_START
	setvar VAR_CUTSCENE_STATE, 9
	setvar VAR_PORTO_BELLA_CITY_STATE, 3
	releaseall
	end

ShrineOfProsperityPresent_Movement_PanCameraUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ShrineOfProsperityPresent_Movement_PanCameraDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
ShrineOfProsperityPast_Movement_WalkToOratorL:
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

ShrineOfProsperityPast_Movement_WalkToOratorM:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	face_up
	step_end

ShrineOfProsperityPast_Movement_WalkToOratorR:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	face_up
	step_end

ShrineOfProsperityPast_Movement_AnabelWalkOffScreen:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ShrineOfProsperityPast_Text_Orator:
	.string "Please, return to your time and\n"
	.string "restore balance to Portabella.\p"
	.string "Something must have happened to\n"
	.string "Landorus in the future.$"