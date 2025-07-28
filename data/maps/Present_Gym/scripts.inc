Present_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_Gym_OnTransition
	.byte 0

Present_Gym_OnTransition:
	end

Present_Gym_EventScript_GymStatue::
	msgbox Present_Gym_Text_GymStatue, MSGBOX_SIGN
	end

Present_Gym_Text_GymStatue:
	.string "Porta Bella City Pokémon Gym$"