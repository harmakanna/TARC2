Present_Concerned_Family_House_MapScripts::
	.byte 0

Present_ConcernedFamilyHouse_EventScript_LookerINeedToThink::
	lockall
	speakername Name_Looker
	msgbox Present_ConcernedFamilyHouse_Text_LookerINeedToThink, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

Present_ConcernedFamilyHouse_Text_LookerINeedToThink:
	.string "Hmm…\p"
	.string "I need some fresh air to think\n"
	.string "about what I just learned…$"