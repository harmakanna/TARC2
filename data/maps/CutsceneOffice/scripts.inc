CutsceneOffice_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneOffice_OnFrame
	.byte 0

CutsceneOffice_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 0, CutsceneOffice_EventScript_StartGame
	.2byte 0

CutsceneOffice_EventScript_StartGame::
	lockall
	setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	special SpawnCameraObject
	waitmovement 0
	setvar VAR_0x8004, 4
	setvar VAR_0x8005, 6
	special TeleportCamera
	msgbox CutsceneOffice_Text_SomewhereInUnova, MSGBOX_DEFAULT
	closemessage
	delay 100
	fadescreen FADE_FROM_BLACK
	@call CutsceneOffice_EventScript_Scene
	fadescreen FADE_TO_BLACK
	delay 60
	special ReturnCameraToPlayer
	setflag FLAG_SYS_SPAWN_INVISIBLE
	setvar VAR_CUTSCENE_STATE, 1
	warpsilent MAP_CUTSCENE_WATER, 0, 11
	waitstate
	releaseall
	end

CutsceneOffice_EventScript_Scene::
	speakername Name_Looker
	msgbox CutsceneOffice_Text_Dots, MSGBOX_DEFAULT
	closemessage
	delay 120
	speakername Name_Looker
	msgbox CutsceneOffice_Text_Dots, MSGBOX_DEFAULT
	closemessage
	delay 120
	speakername Name_Looker
	msgbox CutsceneOffice_Text_Zzz, MSGBOX_DEFAULT
	closemessage
	delay 120
	playse SE_EXIT
	applymovement LOCALID_OFFICE_ANABEL, CutsceneOffice_Movement_AnabelEntersScene
	speakername Name_Anabel
	msgbox CutsceneOffice_Text_AnabelLooker, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_PL_LOOKER, FALSE
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 16
	playse SE_BIKE_HOP
	applymovement LOCALID_PLAYER, CutsceneOffice_Movement_LookerJumpOutOfChair
	delay 10
	playse SE_WALL_HIT
	speakername Name_Looker
	msgbox CutsceneOffice_Text_LookerAhh MSGBOX_DEFAULT
	closemessage
	delay 80
	@speak LOCALID_PLAYER, DIR_EAST, Name_Looker, CutsceneOffice_Text_LookerAnabel
	@speak LOCALID_OFFICE_ANABEL, DIR_WEST, Name_Anabel, CutsceneOffice_Text_AnabelWeReceived
	@speak LOCALID_PLAYER, DIR_EAST, Name_Looker, CutsceneOffice_Text_LookerThePortCity
	@speak LOCALID_OFFICE_ANABEL, DIR_WEST, Name_Anabel, CutsceneOffice_Text_AnabelRecently
	@speak LOCALID_PLAYER, DIR_EAST, Name_Looker, CutsceneOffice_Text_LookerAhAProcedural
	@speak LOCALID_OFFICE_ANABEL, DIR_WEST, Name_Anabel, CutsceneOffice_Text_AnabelKeepSharp
	@speak LOCALID_PLAYER, DIR_EAST, Name_Looker, CutsceneOffice_Text_LookerOhFine
	@speak LOCALID_OFFICE_ANABEL, DIR_WEST, Name_Anabel, CutsceneOffice_Text_AnabelIllReachOut
	closemessage
	delay 40
	return

CutsceneOffice_Movement_AnabelEntersScene:
	face_left
	set_visible
	walk_fast_left
	walk_fast_up
	walk_fast_left
	step_end

CutsceneOffice_Movement_LookerJumpOutOfChair:
	face_right
	lock_facing_direction
	jump_left
	walk_faster_right
	unlock_facing_direction
	step_end

CutsceneOffice_Text_SomewhereInUnova:
	.string "Somewhere, in the region of Unova…$"

CutsceneOffice_Text_Dots:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …$"

CutsceneOffice_Text_Zzz:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Zzz zzz zzz…$"

CutsceneOffice_Text_AnabelLooker:
	.string "LOOKER! We've got work!$"

CutsceneOffice_Text_LookerAhh:
	.string "AHH!$"

CutsceneOffice_Text_LookerAnabel:
	.string "Oww…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Anabel!\p"
	.string "Don't startle me like that!$"

CutsceneOffice_Text_AnabelWeReceived:
	.string "Sorry!\p"
	.string "We just received a job request from the\n"
	.string "mayor of the city of Porta Bella.$"

CutsceneOffice_Text_LookerThePortCity:
	.string "The port city? That sounds like a\n"
	.string "nice change of pace from the office.\p"
	.string "What is he requesting of us?$"

CutsceneOffice_Text_AnabelRecently:
	.string "As you know, Team Aqua went missing\n"
	.string "for quite a while following the events\l"
	.string "at Sootopolis City.\p"
	.string "But within the past three months, they've\n"
	.string "reestablished operations in the city,\l"
	.string "putting its population on high alert.\p"
	.string "Thus, Mayor Morrigan is requesting we do\n"
	.string "an audit of their new facility to ensure\l"
	.string "no trouble is afoot.$"

CutsceneOffice_Text_LookerAhAProcedural:
	.string "Ah, so nothing more than a procedural\n"
	.string "inspection and we should be all set.\p"
	.string "Perhaps we can treat it like a mini-\n"
	.string "vacation, even?$"

CutsceneOffice_Text_AnabelKeepSharp:
	.string "Keep sharp, Looker.\p"
	.string "We don't know what Team Aqua has been\n"
	.string "up to this past year.\p"
	.string "Something serious might be brewing.$"

CutsceneOffice_Text_LookerOhFine:
	.string "Oh fine…\p"
	.string "Let us make preparations for travel and\n"
	.string "depart in a few days, then.\p"
	.string "I trust you with planning out our\n"
	.string "little escapade, in the meantime?$"

CutsceneOffice_Text_AnabelIllReachOut:
	.string "Of course. I'll reach back out to\n"
	.string "Morrigan right away.$"
