PastTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PastTown_OnFrame
	.byte 0

PastTown_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 5, PastTown_EventScript_LookerEnters
	.2byte 0

PastTown_EventScript_LookerEnters::
	end
