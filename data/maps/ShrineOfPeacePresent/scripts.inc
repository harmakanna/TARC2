ShrineOfPeacePresent_MapScripts::
	.byte 0

ShrineOfPeacePresent_Script_Celebi::
	lockall
	faceplayer
	msgbox ShrineOfPeacePresent_Text_CelebiWarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShrineOfPeacePresent_Script_CelebiWarp
	releaseall
	end

ShrineOfPeacePresent_Script_CelebiWarp::
	warpteleport MAP_SHRINE_OF_PEACE_PAST, 14, 9
	waitstate
	releaseall
	end

ShrineOfPeacePresent_Text_CelebiWarp:
	.string "Biii?\p"
	.string "Celebi is looking at you\n"
	.string "expectantly…\p"
	.string "Warp to the past?$"
	
	