CutsceneForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CutsceneForest_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneForest_OnFrame
    .byte 0

CutsceneForest_OnTransition:
	setflag FLAG_SYS_PREVENT_MAP_FADE
	end

CutsceneForest_OnFrame:
    map_script_2 VAR_CUTSCENE_STATE, 5, CutsceneForest_EventScript_SearchForEstella
    .2byte 0

CutsceneForest_EventScript_SearchForEstella::
	lockall
	special SpawnCameraObject
	setvar VAR_0x8004, 10  @ x
	setvar VAR_0x8005, 9  @ y
	special TeleportCamera
	delay 80
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_FROM_BLACK
	delay 10
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_PlayerRunIntoShot
	applymovement LOCALID_FOREST_RANGER, CutsceneForest_Movement_RangerRunIntoShot
	applymovement LOCALID_FOREST_ANABEL, CutsceneForest_Movement_AnabelRunIntoShot
	waitmovement 0
	delay 10
	applymovement LOCALID_FOREST_ANABEL, CutsceneForest_Movement_LookAround1
	applymovement LOCALID_FOREST_RANGER, CutsceneForest_Movement_LookAround2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	speakername Name_Looker
	message CutsceneForest_Text_LookerEstella
	delay 60
	closemessage
	delay 40
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_LookAround3
	applymovement LOCALID_FOREST_RANGER, CutsceneForest_Movement_LookAround4
	applymovement LOCALID_FOREST_ANABEL, Common_Movement_WalkInPlaceFasterRight
	speakername Name_Anabel
	message CutsceneForest_Text_AnabelEstella
	waitmessage
	delay 60
	closemessage
	delay 40
	playse SE_SELECT
	speak LOCALID_FOREST_ANABEL, DIR_WEST, Name_Anabel, CutsceneForest_Text_AnabelDrat
	speak LOCALID_FOREST_RANGER, DIR_EAST, Name_Head_Ranger, CutsceneForest_Text_RangerSeemsLikeShesNotHere
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	playse SE_SELECT
	msgbox CutsceneForest_Text_RangerMeetBackAtCityHall, MSGBOX_DEFAULT
	speak LOCALID_FOREST_ANABEL, DIR_WEST, Name_Anabel, CutsceneForest_Text_AnabelGotIt
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LookerUnderstood
	speak LOCALID_FOREST_RANGER, DIR_EAST, Name_Head_Ranger, CutsceneForest_Text_RangerGreatBeSafe
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LookerOfCourse
	closemessage
	delay 10
	applymovement LOCALID_FOREST_RANGER, CutsceneForest_Movement_RangerRunOutOfShot
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_PlayerRunOutOfShot
	applymovement LOCALID_FOREST_ANABEL, CutsceneForest_Movement_AnabelRunOutOfShot
	waitmovement 0
	delay 200
	applymovement LOCALID_FOREST_CELEBI, CutsceneForest_Movement_CelebiFloatInOutOfShot
	waitmovement 0
	setobjectmovementtype LOCALID_FOREST_CELEBI, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	message CutsceneForest_Text_Celebi
	waitmessage
	delay 80
	closemessage
	applymovement LOCALID_FOREST_CELEBI, CutsceneForest_Movement_CelebiFloatInOutOfShot
	fadescreen FADE_TO_BLACK
	delay 60
	message CutsceneForest_Text_RepelsEffect
	waitmessage
	delay 80
	closemessage
	delay 100
	special ReturnCameraToPlayer
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	warp MAP_SHRINE_OF_PEACE_PRESENT, 14, 28
	end

CutsceneForest_Movement_LookAround1:
	face_up
	delay_16
	face_down
	delay_16
	delay_16
	face_right
	step_end

CutsceneForest_Movement_LookAround2:
	face_left
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	step_end

CutsceneForest_Movement_LookAround3:
	face_left
	delay_16
	face_down
	delay_16
	delay_8
	face_up
	step_end

CutsceneForest_Movement_LookAround4:
	face_down
	delay_16
	delay_16
	delay_8
	face_left
	step_end

CutsceneForest_Movement_CelebiFloatInOutOfShot:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CutsceneForest_Movement_PlayerRunOutOfShot:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
	
CutsceneForest_Movement_RangerRunOutOfShot:
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

CutsceneForest_Movement_AnabelRunOutOfShot:
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

CutsceneForest_Movement_PlayerRunIntoShot:
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	step_end

CutsceneForest_Movement_RangerRunIntoShot:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_8
	face_up
	delay_16
	face_down
	delay_16
	face_left
	step_end

CutsceneForest_Movement_AnabelRunIntoShot:
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_left
	step_end


CutsceneForest_Text_RepelsEffect:
	.string "Repels' effect wore off…$"

CutsceneForest_Text_Celebi:
	.string "Biii…$"

CutsceneForest_Text_AnabelEstella:
	.string "Estellaaaa!$"

CutsceneForest_Text_LookerEstella:
	.string "Estella!$"

CutsceneForest_Text_AnabelGotIt:
	.string "Got it.\n"
	.string "Looker?$"

CutsceneForest_Text_LookerUnderstood:
	.string "I heard.$"

CutsceneForest_Text_RangerGreatBeSafe:
	.string "Great. Please be safe\n"
	.string "out there!$"

CutsceneForest_Text_LookerOfCourse:
	.string "Of course.$"

CutsceneForest_Text_AnabelDrat:
	.string "Drat, there's been no\n"
	.string "sign of her at all out here!$"

CutsceneForest_Text_RangerSeemsLikeShesNotHere:
	.string "She doesn't seem to be in\n"
	.string "this neck of the woods!$"

CutsceneForest_Text_RangerMeetBackAtCityHall:
	.string "Looker.\n"
	.string "Anabel.\p"
	.string "The trail branches off up ahead -\n"
	.string "one way goes to the shrine and the\l"
	.string "other loops back to the entrance.\p"
	.string "I'll take the loop,\n"
	.string "you take the shrine.\p"
	.string "Whether you find her or not, meet\n"
	.string "me back at the Ranger's bureau in\l"
	.string "City Hall later.\p"
	.string "Our office is in the left wing of\n"
	.string "the building. Got it?$"