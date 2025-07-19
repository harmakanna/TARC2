CutsceneForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CutsceneForest_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneForest_OnFrame
    .byte 0

CutsceneForest_OnTransition:
	setflag FLAG_SYS_PREVENT_MAP_FADE
	end

CutsceneForest_OnFrame:
    map_script_2 VAR_CUTSCENE_STATE, 3, CutsceneForest_EventScript_SearchForEstella
    .2byte 0

CutsceneForest_EventScript_SearchForEstella::
	lockall
	special SpawnCameraObject
	setvar VAR_0x8004, 10  @ x
	setvar VAR_0x8005, 9  @ y
	special TeleportCamera
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_FROM_BLACK
	delay 10
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_PlayerRunIntoShot
	applymovement LOCALID_FOREST_RANGER, CutsceneForest_Movement_RangerRunIntoShot
	applymovement LOCALID_FOREST_ANABEL, CutsceneForest_Movement_AnabelRunIntoShot
	waitmovement 0
	delay 10
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox CutsceneForest_Text_LookerEstella, MSGBOX_DEFAULT
	delay 20
	closemessage
	delay 10
	applymovement LOCALID_FOREST_ANABEL, Common_Movement_WalkInPlaceFasterRight
	msgbox CutsceneForest_Text_AnabelEstella, MSGBOX_DEFAULT
	delay 20
	closemessage
	delay 40
	applymovement LOCALID_FOREST_ANABEL, Common_Movement_WalkInPlaceFasterRight
	msgbox CutsceneForest_Text_AnabelDrat, MSGBOX_DEFAULT
	applymovement LOCALID_FOREST_RANGER, Common_Movement_WalkInPlaceFasterLeft
	msgbox CutsceneForest_Text_RangerSeemsLikeShesNotHere, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_FOREST_RANGER, Common_Movement_FaceRight
	applymovement LOCALID_FOREST_ANABEL, Common_Movement_FaceLeft
	msgbox CutsceneForest_Text_RangerMeetBackAtCityHall, MSGBOX_DEFAULT
	applymovement LOCALID_FOREST_ANABEL, Common_Movement_WalkInPlaceFasterLeft
	msgbox CutsceneForest_Text_AnabelGotIt, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox CutsceneForest_Text_LookerUnderstood, MSGBOX_DEFAULT
	applymovement LOCALID_FOREST_RANGER, Common_Movement_WalkInPlaceFasterRight
	msgbox CutsceneForest_Text_RangerGreatBeSafe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox CutsceneForest_Text_LookerOfCourse, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_FOREST_RANGER, CutsceneForest_Movement_RangerRunOutOfShot
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_PlayerRunOutOfShot
	applymovement LOCALID_FOREST_ANABEL, CutsceneForest_Movement_AnabelRunOutOfShot
	waitmovement 0
	delay 200
	applymovement LOCALID_FOREST_CELEBI, CutsceneForest_Movement_CelebiFloatInOutOfShot
	waitmovement 0
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Celebi, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_FOREST_CELEBI, CutsceneForest_Movement_CelebiFloatInOutOfShot
	fadescreen FADE_TO_BLACK
	special ReturnCameraToPlayer
	warp MAP_SHRINE_OF_PEACE_PRESENT, 14, 21
	end

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
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
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

CutsceneForest_Text_Celebi:
	.string "Biii…$"

CutsceneForest_Text_AnabelEstella:
	.string "Anabel: Estellaaaa!$"

CutsceneForest_Text_LookerEstella:
	.string "Looker: Estella!$"

CutsceneForest_Text_AnabelGotIt:
	.string "Anabel: Got it.\n"
	.string "Looker?$"

CutsceneForest_Text_LookerUnderstood:
	.string "Looker: I heard.$"

CutsceneForest_Text_RangerGreatBeSafe:
	.string "Ranger: Great. Please be safe\n"
	.string "out there!$"

CutsceneForest_Text_LookerOfCourse:
	.string "Looker: Of course.$"

CutsceneForest_Text_AnabelDrat:
	.string "Anabel: Drat, there's been no\n"
	.string "sign of her at all out here!$"

CutsceneForest_Text_RangerSeemsLikeShesNotHere:
	.string "Ranger: She doesn't seem to be in\n"
	.string "this neck of the woods!$"

CutsceneForest_Text_RangerMeetBackAtCityHall:
	.string "Looker,\n"
	.string "Anabel,\p"
	.string "the trail branches off up ahead -\n"
	.string "one way goes to the shrine and the\l"
	.string "other loops back to the entrance.\p"
	.string "I'll take the loop,\n"
	.string "you take the shrine.\p"
	.string "Whether you find her or not, meet\n"
	.string "me back at the Ranger's bureau in\l"
	.string "City Hall later.\p"
	.string "Our office is in the left wing of\n"
	.string "the building. Got it?$"