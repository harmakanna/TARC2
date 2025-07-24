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
	lockall
	releaseall
	end

ShrineOfProsperityPast_EventScript_LandorusMyth::
	lockall
	setflag FLAG_SYS_MAIN_GAME_START
	releaseall
	end
	