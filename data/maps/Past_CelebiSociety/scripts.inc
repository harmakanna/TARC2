Past_CelebiSociety_MapScripts::
	.byte 0

Past_CelebiSociety_EventScript_CouncilWoman::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Past_CelebiSociety_EventScript_CouncilWomanPreGame
	goto_if_set FLAG_SAVE_THE_LUVDISCS, Past_CelebiSociety_EventScript_CouncilWomanSaveLuvdiscs
	msgbox Past_CelebiSociety_Text_CouncilWomanAhAnotherTimeTraveler, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_CelebiSociety_EventScript_CouncilWomanPreGame::
	msgbox Past_CelebiSociety_Text_CouncilWomanPregame, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_CelebiSociety_EventScript_CouncilWomanSaveLuvdiscs::
	msgbox Past_CelebiSociety_Text_CouncilWomanSaveLuvdiscs, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_SS_TIDAL
	clearflag FLAG_SAVE_THE_LUVDISCS
	clearflag FLAG_HIDE_PRESENT_LUVDISCS
	clearflag FLAG_HIDE_PRESENT_HOUSE2_MISSINGMAN
	clearflag FLAG_HIDE_TINY_BOAT
	release
	end

Past_CelebiSociety_Text_CouncilWomanPregame:
	.string "Ah, another time traveler.\p"
	.string "This might sound strange, but please\n"
	.string "do enjoy your stay in this era!$"

Past_CelebiSociety_Text_CouncilWomanAhAnotherTimeTraveler:
	.string "Ah, another time traveler.\p"
	.string "If you ever want something changed\n"
	.string "about the future, please let me know.\p"
	.string "I can assure you such a thing will\n"
	.string "not have any negative effects on the\l"
	.string "timeline!$"

Past_CelebiSociety_Text_CouncilWomanSaveLuvdiscs:
	.string "Excuse me, sir, did you say that\n"
	.string "large ship traffic in the future\l"
	.string "threatens our precious ecosystem?\p"
	.string "That sounds horrid!\p"
	.string "Thank you for informing me, I will\n"
	.string "ensure such a thing never happens!$"