Present_PokemonCenter_MapScripts::
	.byte 0

Present_PokemonCenter_EventScript_Nurse::
	lock
	goto_if_set FLAG_SYS_WEATHER_CTRL, Present_PokemonCenter_EventScript_NurseStorm
	speakername Name_Nurse
	msgbox Present_PokemonCenter_Text_NurseHealthy, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_PokemonCenter_EventScript_NurseStorm::
	speakername Name_Nurse
	msgbox Present_PokemonCenter_Text_NurseStorm, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Present_PokemonCenter_EventScript_Blissey::
	lock
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox Present_PokemonCenter_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

Present_PokemonCenter_EventScript_Zangoose::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZANGOOSE, CRY_MODE_NORMAL
	msgbox Present_PokemonCenter_Text_Zangoose, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

Present_PokemonCenter_Text_Blissey:
	.string "Blisssss!$"

Present_PokemonCenter_Text_Zangoose:
	.string "Grrrrr…$"

Present_PokemonCenter_Text_NurseStorm:
	.string "Hello! Welcome to the Pokémon Center!\p"
	.string "While the storm is raging on outside, feel\n"
	.string "free to use this Pokémon Center as a refuge!\p"
	.string "There have been reports that Pokémon are\n"
	.string "running wild outside!$"

Present_PokemonCenter_Text_NurseHealthy:
	.string "Hello! Welcome to the Pokémon Center!\p"
	.string "I see your Pokémon are quite healthy!\n"
	.string "I hope you have a wonderful day!$" 