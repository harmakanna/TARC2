ShrineOfPeacePast_MapScripts::
	.byte 0

ShrineOfPeacePast_Script_Celebi::
	lockall
	faceplayer
	msgbox ShrineOfPeacePast_Text_CelebiWarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShrineOfPeacePast_Script_CelebiWarp
	releaseall
	end

ShrineOfPeacePast_Script_CelebiWarp::
	warpteleport MAP_SHRINE_OF_PEACE_PRESENT, 14, 9
	waitstate
	releaseall
	end

ShrineOfPeacePast_Text_CelebiWarp:
	.string "Biii?\p"
	.string "Celebi is looking at you\n"
	.string "expectantly…\p"
	.string "Warp to the present?$"
	
