Present_Concerned_Family_House_2F_MapScripts::
	.byte 0

Present_ConcernedFamilyHouse_EventScript_Son::
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_ConcernedFamilyHouse_EventScript_SonPregame
	msgbox Present_ConcernedFamilyHouse_Text_SonSkittyKitty, MSGBOX_NPC
	end

Present_ConcernedFamilyHouse_EventScript_SonPregame:
	msgbox Present_ConcernedFamilyHouse_Text_SonPregame, MSGBOX_NPC
	end

Present_ConcernedFamilyHouse_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox Present_ConcernedFamilyHouse_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

Present_ConcernedFamilyHouse_Text_Skitty:
	.string "Maow!$"

Present_ConcernedFamilyHouse_Text_SonPregame:
	.string "skitty kitty kitty skitty\p"
	.string "skitty kitty\n"
	.string "kitty skitty\p"
	.string "kitty kitty\n"
	.string "skitty skitty\p"
	.string "MROAW!!!$"

Present_ConcernedFamilyHouse_Text_SonSkittyKitty:
	.string "skitty kitty kitty skitty\p"
	.string "skitty kitty\n"
	.string "kitty skitty\p"
	.string "kitty kitty\n"
	.string "skitty skitty\p"
	.string "thanks for getting my sister\n"
	.string "home from the woods\p"
	.string "MROAW!!!$"