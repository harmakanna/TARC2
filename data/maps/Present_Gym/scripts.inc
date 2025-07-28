Present_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_Gym_OnTransition
	.byte 0

Present_Gym_OnTransition:
	@call Present_Gym_EventScript_SetFlashLevel
	end
