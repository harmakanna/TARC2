ShrineOfPeacePresent_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShrineOfPeacePresent_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, ShrineOfPeacePresent_OnFrame
	.byte 0

ShrineOfPeacePresent_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 3, ShrineOfPeacePresent_EventScript_CelebiEncounterSetup
	end

ShrineOfPeacePresent_EventScript_CelebiEncounterSetup::
	setobjectxyperm LOCALID_SHRINE_PRESENT_CELEBI, 14, 28
	setflag FLAG_SYS_PREVENT_MAP_FADE
	return

ShrineOfPeacePresent_OnFrame:
    map_script_2 VAR_CUTSCENE_STATE, 3, ShrineOfPeacePresent_EventScript_CelebiEncounter
    .2byte 0

ShrineOfPeacePresent_EventScript_CelebiEncounter::
	lockall
	delay 80
	special SpawnCameraObject
	setvar VAR_0x8004, 14  @ x
	setvar VAR_0x8005, 22  @ y
	special TeleportCamera
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_FROM_BLACK
	delay 10
	applymovement LOCALID_PLAYER, ShrineOfPeacePresent_Movement_RunToCenterCamera1
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, ShrineOfPeacePresent_Movement_RunToCenterCamera2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, Common_Movement_FaceLeft
	msgbox ShrineOfPeacePresent_Text_AnabelAlmostToTheShrine, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAMERA, ShrineOfPeacePresent_Movement_CameraTrailLooker
	@applymovement LOCALID_SHRINE_PRESENT_CELEBI, ShrineOfPeacePresent_CelebiFollowCamera
	applymovement LOCALID_PLAYER, ShrineOfPeacePresent_Movement_LookerRunToShrine
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, ShrineOfPeacePresent_Movement_AnabelRunToShrine
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceUpExclamationMark
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, Common_Movement_FaceUpExclamationMark
	delay 48
	playse SE_SELECT
	msgbox ShrineOfPeacePresent_Text_LookerLookUpAhead, MSGBOX_DEFAULT
	closemessage
	setobjectxyperm LOCALID_SHRINE_PRESENT_CELEBI, 14, 21
	delay 20
	applymovement LOCALID_CAMERA, ShrineOfPeacePresent_Movement_PanCameraToShrine
	waitmovement 0
	delay 40
	applymovement LOCALID_CAMERA, ShrineOfPeacePresent_Movement_PanCameraToLooker
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, Common_Movement_FaceLeft
	playse SE_SELECT
	msgbox ShrineOfPeacePresent_Text_AnabelItsTooDangerous, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, Common_Movement_FaceDownExclamationMark
	delay 48
	playse SE_SELECT
	msgbox ShrineOfPeacePresent_Text_AnabelOhNo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	playse SE_SELECT
	msgbox ShrineOfPeacePresent_Text_AnabelWhatNow, MSGBOX_DEFAULT
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	msgbox ShrineOfPeacePresent_Text_CelebiBii1, MSGBOX_DEFAULT
	msgbox ShrineOfPeacePresent_Text_AnabelShoutsLooker, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceRightExclamationMark
	playse SE_PIN
	waitse
	playse SE_WARP_IN
	applymovement LOCALID_SHRINE_PEACE_PRESENT_ANABEL, ShrineOfPeacePresent_Movement_TeleportAway
	waitmovement 0
	removeobject LOCALID_SHRINE_PEACE_PRESENT_ANABEL
	setflag FLAG_HIDE_SHRINE_PEACE_PRESENT_ANABEL
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	msgbox ShrineOfPeacePresent_Text_LookerAnabel, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	delay 48
	playse SE_SELECT
	msgbox ShrineOfPeacePresent_Text_LookerHuh, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_SHRINE_PRESENT_CELEBI, ShrineOfPeacePresent_Movement_CelebiEnterShot
	applymovement LOCALID_CAMERA, ShrineOfPeacePresent_Movement_CameraPanToCelebi
	waitmovement 0
	setobjectmovementtype LOCALID_SHRINE_PRESENT_CELEBI, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP
	delay 60
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	msgbox ShrineOfPeacePresent_Text_CelebiBii2, MSGBOX_DEFAULT
	delay 40
	closemessage
	playse SE_WARP_IN
	applymovement LOCALID_PLAYER, ShrineOfPeacePresent_Movement_TeleportAway
	fadescreen FADE_TO_BLACK
	warpsilent MAP_SHRINE_OF_PEACE_PAST, 14, 9
	end

ShrineOfPeacePresent_Movement_CameraPanToCelebi:
	walk_down
	walk_down
	step_end

ShrineOfPeacePresent_Movement_CelebiEnterShot:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

ShrineOfPeacePresent_Movement_TeleportAway:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	step_end

ShrineOfPeacePresent_Movement_RunToCenterCamera1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ShrineOfPeacePresent_Movement_RunToCenterCamera2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ShrineOfPeacePresent_Movement_CameraTrailLooker:
    delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ShrineOfPeacePresent_Movement_LookerRunToShrine:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
	
ShrineOfPeacePresent_Movement_AnabelRunToShrine:
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ShrineOfPeacePresent_Movement_PanCameraToShrine:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ShrineOfPeacePresent_Movement_PanCameraToLooker:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

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

ShrineOfPeacePresent_Text_LookerHuh:
	.string "Looker: Huh…?\p"
	.string "What's that…?$"

ShrineOfPeacePresent_Text_AnabelAlmostToTheShrine:
	.string "Anabel: I see a clearing up ahead!\n"
	.string "I think we're almost to the shrine!$"

ShrineOfPeacePresent_Text_LookerLookUpAhead:
	.string "Looker: Anabel, look up ahead!$"

ShrineOfPeacePresent_Text_AnabelItsTooDangerous:
	.string "Anabel: Shoot, I think our repels\n"
	.string "wore off and we didn't even notice!\p"
	.string "Looker, it's too dangerous! We can't\n"
	.string "save Estella if we're in danger\l"
	.string "ourselves!\p"
	.string "We NEED to turn back!$"

ShrineOfPeacePresent_Text_AnabelOhNo:
	.string "Oh no…$"

ShrineOfPeacePresent_Text_AnabelWhatNow:
	.string "We're surrounded!\p"
	.string "What do we do now? There's too\n"
	.string "many to fight, even for us!$"

ShrineOfPeacePresent_Text_CelebiBii1:
	.string "Biii!$"

ShrineOfPeacePresent_Text_CelebiBii2:
	.string "Biiiiiii!$"

ShrineOfPeacePresent_Text_AnabelShoutsLooker:
	.string "Anabel: Looker, help!$"

ShrineOfPeacePresent_Text_LookerAnabel:
	.string "Looker: Anabel…$"	

ShrineOfPeacePresent_Text_RepelsEffect:
	.string "Repels' effect wore off…$"
