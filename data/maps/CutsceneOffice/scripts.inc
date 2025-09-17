CutsceneOffice_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneOffice_OnFrame
	.byte 0

CutsceneOffice_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 0, CutsceneOffice_EventScript_StartGame
	.2byte 0

CutsceneOffice_EventScript_StartGame::
	lockall
	setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	message CutsceneOffice_Text_PleaseSetDifficulty
	waitmessage
	multichoicedefault 0, 0, MULTI_CHOOSE_DIFFICULTY, 1, TRUE
	call_if_eq VAR_RESULT, 0, CutsceneOffice_EventScript_SetEasy
	call_if_eq VAR_RESULT, 1, CutsceneOffice_EventScript_SetNormal
	call_if_eq VAR_RESULT, 2, CutsceneOffice_EventScript_SetHard
	special SetDifficulty @Resets battle speed, doesn't touch difficulty any more
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	special SpawnCameraObject
	waitmovement 0
	delay 120
	setvar VAR_0x8004, 4
	setvar VAR_0x8005, 6
	special TeleportCamera
	message CutsceneOffice_Text_SomewhereInUnova
	waitmessage
	delay 120
	closemessage
	delay 100
	fadescreen FADE_FROM_BLACK
	call CutsceneOffice_EventScript_Scene
	fadescreen FADE_TO_BLACK
	delay 60
	special ReturnCameraToPlayer
	setflag FLAG_SYS_SPAWN_INVISIBLE
	warpsilent MAP_CUTSCENE_WATER, 0, 11
	waitstate
	releaseall
	end

CutsceneOffice_EventScript_SetEasy::
	playse SE_SELECT
	msgbox CutsceneOffice_Text_SetToEasy, MSGBOX_DEFAULT
	msgbox CutsceneOffice_Text_BattleSpeed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CHOOSE_DIFFICULTY, 0
	setdifficulty DIFFICULTY_EASY 
	return

CutsceneOffice_EventScript_SetNormal::
	playse SE_SELECT
	msgbox CutsceneOffice_Text_SetToNormal, MSGBOX_DEFAULT
	msgbox CutsceneOffice_Text_BattleSpeed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CHOOSE_DIFFICULTY, 1
	setdifficulty DIFFICULTY_NORMAL
	return

CutsceneOffice_EventScript_SetHard::
	playse SE_SELECT
	msgbox CutsceneOffice_Text_SetToHard, MSGBOX_DEFAULT
	msgbox CutsceneOffice_Text_BattleSpeed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CHOOSE_DIFFICULTY, 2
	setdifficulty DIFFICULTY_HARD
	return

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
	message CutsceneOffice_Text_AnabelLooker
	waitmessage
	delay 10
	playbgm MUS_PL_LOOKER, FALSE
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 16
	applymovement LOCALID_PLAYER, CutsceneOffice_Movement_LookerJumpOutOfChair
	speakername Name_Looker
	message CutsceneOffice_Text_LookerAhh
	playse SE_BIKE_HOP
	waitse
	playse SE_EFFECTIVE
	waitmessage
	delay 10
	closemessage
	delay 80
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, CutsceneOffice_Text_LookerAnabel
	speak LOCALID_OFFICE_ANABEL, DIR_WEST, Name_Anabel, CutsceneOffice_Text_AnabelWeReceived
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, CutsceneOffice_Text_LookerThePortCity
	speak LOCALID_OFFICE_ANABEL, DIR_WEST, Name_Anabel, CutsceneOffice_Text_AnabelRecently
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, CutsceneOffice_Text_LookerAhAProcedural
	speak LOCALID_OFFICE_ANABEL, DIR_WEST, Name_Anabel, CutsceneOffice_Text_AnabelKeepSharp
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, CutsceneOffice_Text_LookerOhFine
	speak LOCALID_OFFICE_ANABEL, DIR_WEST, Name_Anabel, CutsceneOffice_Text_AnabelIllReachOut
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
	.string "AAAAAAAAAAHHH!$"

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
	.string "The port city?\p"
	.string "What is he requesting of us?$"

CutsceneOffice_Text_AnabelRecently:
	.string "As you know, Team Aqua went missing\n"
	.string "for quite a while following the events\l"
	.string "at Sootopolis City.\p"
	.string "But in the past three months, they've\n"
	.string "reestablished operations in the city,\l"
	.string "putting its population on high alert.\p"
	.string "Thus, Mayor Morrigan is requesting we\n"
	.string "do an audit of their new facility to\l"
	.string "ensure no trouble is afoot.$"

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

CutsceneOffice_Text_PleaseSetDifficulty:
	.string "Please set your difficulty.\n"
	.string "(This can be changed at any time.)$"

CutsceneOffice_Text_SetToEasy:
	.string "The difficulty has been set to\n"
	.string "'Easy'.$"
	
CutsceneOffice_Text_SetToNormal:
	.string "The difficulty has been set to\n"
	.string "'Normal'.$"
	
CutsceneOffice_Text_SetToHard:
	.string "The difficulty has been set to\n"
	.string "'Hard'.$"

CutsceneOffice_Text_BattleSpeed:
	.string "Battle speed has been set to 1x.$"
	