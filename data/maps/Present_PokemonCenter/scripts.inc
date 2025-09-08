Present_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Present_PokemonCenter_OnResume
	.byte 0

Present_PokemonCenter_OnResume:
	special HealPlayerParty
	end
	
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
	
Present_PokemonCenter_EventScript_Idol::
	lock
	faceplayer
	call Script_GetNPCFacingDirection
	speakername Name_Left_Idol
	speak LOCALID_POKEMON_CENTER_IDOL, VAR_0x8005, Name_Right_Idol, Present_PokemonCenter_Text_IdolIGotSeparated
	returnqueststate QUEST_GET_INTO_THE_GROOVE
	goto_if_eq VAR_RESULT, 2, Present_PokemonCenter_EventScript_IdolQuest
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ThatIsTroubling
	closemessage
	release
	end

Present_PokemonCenter_EventScript_IdolQuest::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_LetMeExplain
	call_if_eq VAR_NUM_FOUND_IDOLS, 2, Present_PokemonCenter_EventScript_IdolYouFoundThemAll
	call_if_ne VAR_NUM_FOUND_IDOLS, 2, Present_PokemonCenter_EventScript_IdolPleaseFindMyFriends
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_POKEMON_CENTER_IDOL
	removeobject LOCALID_POKEMON_CENTER_PACHIRISU
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_HIDE_CAFE_IDOL_LEFT
	addvar VAR_NUM_FOUND_IDOLS, 1
	goto_if_eq VAR_NUM_FOUND_IDOLS, 3, Looker_EventScript_FoundAllIdols
	release
	end

Present_PokemonCenter_EventScript_IdolYouFoundThemAll::
	playse SE_PIN
	applymovement LOCALID_POKEMON_CENTER_IDOL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 50
	speak LOCALID_POKEMON_CENTER_IDOL, VAR_0x8005, Name_Left_Idol, Present_PokemonCenter_Text_IdolYouFoundThemAll
	return

Present_PokemonCenter_EventScript_IdolPleaseFindMyFriends::
	speak LOCALID_POKEMON_CENTER_IDOL, VAR_0x8005, Name_Left_Idol, Present_PokemonCenter_Text_IdolPleaseFindMyFriends
	return

Present_PokemonCenter_EventScript_Hiker::
	speakername Name_Hiker
	msgbox Present_PokemonCenter_Text_Hiker, MSGBOX_NPC
	end

Present_PokemonCenter_EventScript_Cooltrainer::
	speakername Name_Center_Cooltrainer
	msgbox Present_PokemonCenter_Text_Cooltrainer, MSGBOX_NPC
	end

Present_PokemonCenter_EventScript_Pachirisu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PACHIRISU, CRY_MODE_NORMAL
	msgbox Present_PokemonCenter_Text_Pachirisu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_POKEMON_CENTER_PACHIRISU, Common_Movement_FaceOriginalDirection
	waitmovement 0
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

Present_PokemonCenter_Text_Pachirisu:
	.string "Pa!$"

Present_PokemonCenter_Text_Hiker:
	.string "Hoooo…\p"
	.string "I tried hiking up the mountains which\n"
	.string "surround this city, but I was hit with\l"
	.string "intense fatigue and hallucinations!\p"
	.string "I thought I spotted a pile of moss,\n"
	.string "twigs, and leaves slithering along the\l"
	.string "forest floor…\p"
	.string "Maybe I'm not cut out for hiking…$"

Present_PokemonCenter_Text_IdolIGotSeparated:
	.string "Man… that was scary…\p"
	.string "My troupe and I…\p"
	.string "We got attacked by wild Pokémon on the\n"
	.string "onset of the hurricane.\p"
	.string "I managed to get away unscathed, but\n"
	.string "the other two ran off into the forest.\p"
	.string "I hope they're all right…$"

Present_PokemonCenter_Text_IdolYouFoundThemAll:
	.string "Yo? They're all waiting for me at the\n"
	.string "Tauros Café?\p"
	.string "Awesome! I gotta get over there, ASAP!\p"
	.string "Thanks for letting me know!$"

Present_PokemonCenter_Text_IdolPleaseFindMyFriends:
	.string "I'm needed at the Tauros Café ahead\n"
	.string "of our performance tonight?\p"
	.string "I guess I can wait for them there.\p"
	.string "If you're not busy, could you please\n"
	.string "look for the other two members of my\l"
	.string "troupe?\p"
	.string "I'm super worried for them…$"
	
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

Present_PokemonCenter_Text_Cooltrainer:
	.string "Man, I hyped myself up SO much going\n"
	.string "into the gym challenge this year after\l"
	.string "falling short in Hoenn.\p"
	.string "Imagine my surprise when I reached the\n"
	.string "gym leader here and saw who it was…$"
	