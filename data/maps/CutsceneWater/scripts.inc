CutsceneWater_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneWater_OnFrame
	.byte 0

CutsceneWater_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 0, CutsceneWater_EventScript_StartGame
	.2byte 0

CutsceneWater_EventScript_StartGame::
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 5
	special TeleportCamera
	delay 40
	msgbox CutsceneWater_Text_ThreeDaysLater, MSGBOX_DEFAULT
	closemessage
	delay 80
	fadescreen FADE_FROM_BLACK
	playse SE_SHIP
	waitse
	@delay 60
	@applymovement LOCALID_SHIP, CutsceneWater_Movement_ShipToCenterCamera
	@waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_SHIP, CutsceneWater_Movement_InfiniteMovement
	applymovement LOCALID_CAMERA, CutsceneWater_Movement_InfiniteMovement
	delay 60
	speakername Name_Looker
	message CutsceneWater_Text_LookerSoHasAqua
	waitmessage
	delay 80
	closemessage
	delay 40
	speakername Name_Anabel
	message CutsceneWater_Text_AnabelNotToMyUnderstanding
	waitmessage
	delay 60
	closemessage
	delay 40
	speakername Name_Looker
	message CutsceneWater_Text_LookerIsThisJustACheckIn
	waitmessage
	delay 80
	closemessage
	delay 40
	speakername Name_Anabel
	message CutsceneWater_Text_AnabelYup
	waitmessage
	delay 50
	closemessage
	delay 40
	speakername Name_Looker
	message CutsceneWater_Text_LookerNeat
	waitmessage
	delay 50
	closemessage
	delay 100
	speakername Name_Anabel
	message CutsceneWater_Text_AnabelWereAlmostThere
	waitmessage
	delay 80
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	delay 40
	setflag FLAG_SYS_PREVENT_MAP_FADE
	setflag FLAG_SYS_SPAWN_INVISIBLE
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	special ReturnCameraToPlayer
	special RemoveCameraObject
	warp MAP_PRESENT_TOWN_PORT, 3, 9
	releaseall
	end

CutsceneWater_Movement_ShipToCenterCamera:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CutsceneWater_Movement_InfiniteMovement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CutsceneWater_Text_LookerSoHasAqua:
	.string "So has Team Aqua actually done anything\n"
	.string "yet to earn the ire of the city?$"

CutsceneWater_Text_AnabelNotToMyUnderstanding:
	.string "Not to my understanding.$"

CutsceneWater_Text_LookerIsThisJustACheckIn:
	.string "So we're just getting paid for a routine\n"
	.string "check-in?$"

CutsceneWater_Text_AnabelYup:
	.string "Yup.$"

CutsceneWater_Text_LookerNeat:
	.string "Neat.$"

CutsceneWater_Text_AnabelWereAlmostThere:
	.string "Look! The city's coming into view!$"

CutsceneWater_Text_ThreeDaysLater:
	.string "Three days later…$"
