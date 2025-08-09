Present_School_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PresentSchool_OnTransition
	.byte 0

PresentSchool_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, PresentSchool_EventScript_ForcePlayMusic
	end

PresentSchool_EventScript_ForcePlayMusic::
	playbgm MUS_DP_SUNYSHORE_DAY, FALSE
	return