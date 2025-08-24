Present_PokemonCenter_MapScripts::
	.byte 0

Present_PokemonCenter_EventScript_Nurse::
	lock
	returnqueststate QUEST_SENT_TO_THE_FARM
	goto_if_eq VAR_RESULT, 2, Present_PokemonCenter_EventScript_NurseGiveFullRestores
	goto_if_set FLAG_SYS_WEATHER_CTRL, Present_PokemonCenter_EventScript_NurseStorm
	speakername Name_Nurse
	msgbox Present_PokemonCenter_Text_NurseHealthy, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_PokemonCenter_EventScript_NurseGiveFullRestores::
	speakername Name_Nurse
	msgbox Present_PokemonCenter_Text_NurseWelcome, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_SoHeresTheThing
	speakername Name_Nurse
	msgbox Present_PokemonCenter_Text_NurseTryThis, MSGBOX_DEFAULT
	speakername NULL
	giveitem ITEM_FULL_RESTORE
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ThankYou
	applymovement LOCALID_PRESENT_NURSE, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	speakername Name_Nurse
	msgbox Present_PokemonCenter_Text_NurseWeHopeToSeeYouAgain
	closemessage
	questmenu QUEST_MENU_SET_REWARD, QUEST_SENT_TO_THE_FARM
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

Present_PokemonCenter_Text_NurseWelcome:
	.string "Hello! Welcome to the Pokémon Center!\p"
	.string "Please let me know if there is anything\n"
	.string "I can do to help you!$"

Present_PokemonCenter_Text_NurseTryThis:
	.string "Oh, there's a Tauros and Miltank who are\n"
	.string "feeling terribly sick?\p"
	.string "Try this. These Full Restores can help\n"
	.string "any Pokémon feel chipper and active!$"
	
Present_PokemonCenter_Text_NurseWeHopeToSeeYouAgain:
	.string "My pleasure! We hope your Pokémon start\n"
	.string "to feel better soon!$"
	
Present_PokemonCenter_Text_NurseStorm:
	.string "Hello! Welcome to the Pokémon Center!\p"
	.string "While the storm is raging on outside,\n"
	.string "our Center will accept anyone looking\l"
	.string "for refuge!\p"
	.string "There have been reports that Pokémon\n"
	.string "are running wild outside, after all!$"

Present_PokemonCenter_Text_NurseHealthy:
	.string "Hello! Welcome to the Pokémon Center!\p"
	.string "I see your Pokémon are quite healthy!\n"
	.string "I hope you have a wonderful day!$" 