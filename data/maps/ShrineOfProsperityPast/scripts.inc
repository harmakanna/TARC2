ShrineOfProsperityPast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShrineOfProsperityPast_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ShrineOfProsperityPast_OnResume
	.byte 0

ShrineOfProsperityPast_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 8, ShrineOfProsperityPast_EventScript_SetupMyth
	end

ShrineOfProsperityPast_EventScript_SetupMyth::
	setobjectmovementtype LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, MOVEMENT_TYPE_FACE_LEFT
	return

ShrineOfProsperityPast_OnResume:
	special HealPlayerParty
	end
	
ShrineOfProsperityPast_EventScript_VillageOrator::
	msgbox ShrineOfProsperityPast_Text_Orator, MSGBOX_NPC
	end

ShrineOfProsperityPast_EventScript_StartLandorusMyth::
	lockall
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraUp
	waitmovement 0
	delay 60
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraDown
	waitmovement 0
	special RemoveCameraObject
	delay 40
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	goto_if_eq VAR_TEMP_1, 11, ShrineOfProsperityPast_EventScript_StartLandorusMythL
	goto_if_eq VAR_TEMP_1, 12, ShrineOfProsperityPast_EventScript_StartLandorusMythM
	goto ShrineOfProsperityPast_EventScript_StartLandorusMythR
	end

ShrineOfProsperityPast_EventScript_StartLandorusMythL::
	applymovement LOCALID_PLAYER, ShrineOfProsperityPast_Movement_WalkToOratorL
	waitmovement 0
	goto ShrineOfProsperityPast_EventScript_LandorusMyth
	end

ShrineOfProsperityPast_EventScript_StartLandorusMythM::
	applymovement LOCALID_PLAYER, ShrineOfProsperityPast_Movement_WalkToOratorM
	waitmovement 0
	goto ShrineOfProsperityPast_EventScript_LandorusMyth
	end

ShrineOfProsperityPast_EventScript_StartLandorusMythR::
	applymovement LOCALID_PLAYER, ShrineOfProsperityPast_Movement_WalkToOratorR
	waitmovement 0
	goto ShrineOfProsperityPast_EventScript_LandorusMyth
	end

ShrineOfProsperityPast_EventScript_LandorusMyth::
	speak LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, DIR_SOUTH, Name_Anabel, ShrineOfProsperitPast_Text_AnabelCompanionArrived
	speak LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, DIR_SOUTH, Name_Orator, ShrineOfProsperityPast_Text_OratorWonderful
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, ShrineOfProsperityPast_Text_LookerAsWellAsICouldBe
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, Common_Movement_FaceLeft
	speak LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, DIR_EAST, Name_Anabel, ShrineOfProsperityPast_Text_AnabelWereHere
	speak LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, DIR_WEST, Name_Orator, ShrineOfProsperityPast_Text_OratorMustBeTornThund
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, Common_Movement_FaceDown
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, Common_Movement_FaceDown
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, ShrineOfProsperityPast_Text_LookerSpiritsOfWindAndStorms
	speak LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, DIR_SOUTH, Name_Orator, ShrineOfProsperityPast_Text_OratorYesTheSpirits
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, Common_Movement_FaceLeft
	speak LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, DIR_WEST, Name_Anabel, ShrineOfProsperityPast_Text_AnabelWhatHappened
	speak LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, DIR_EAST, Name_Orator, ShrineOfProsperityPast_Text_OratorStartFromBeginning
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	delay 80
	speakername Name_Orator
	message ShrineOfProsperityPast_Text_OratorThisIsALegend
	waitmessage
	delay 80
	closemessage
	delay 80
	setflag FLAG_SYS_SPAWN_INVISIBLE
	setflag FLAG_SYS_PREVENT_MAP_FADE
	warpsilent MAP_CUTSCENE_MYTH, 56, 41
	goto ShrineOfProsperityPast_EventScript_EndLandorusMyth
	end

ShrineOfProsperityPast_EventScript_EndLandorusMyth::
	lockall
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, ShrineOfProsperityPast_Movement_AnabelWalkOffScreen
	waitmovement 0
	delay 40
	removeobject LOCALID_SHRINE_PROSPERITY_PAST_ANABEL
	clearflag FLAG_HIDE_SHRINE_PEACE_CELEBI
	clearflag FLAG_LOCK_CITY_DOORS
	setflag FLAG_HIDE_PAST_TOWN_HALL_ESTELLA
	setflag FLAG_HIDE_CITYHALL_1F_CONCERNED_DAD
	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_MAIN_GAME_START
	setvar VAR_CUTSCENE_STATE, 9
	setvar VAR_PORTO_BELLA_CITY_STATE, 3
	setvar VAR_QUEUE_GENIE_FIGHT, 1
	setvar VAR_PRESENT_GYM_STATE, 1
	releaseall
	end

ShrineOfProsperityPresent_Movement_PanCameraUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ShrineOfProsperityPresent_Movement_PanCameraDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ShrineOfProsperityPast_Movement_WalkToOratorL:
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

ShrineOfProsperityPast_Movement_WalkToOratorM:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	face_up
	step_end

ShrineOfProsperityPast_Movement_WalkToOratorR:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	face_up
	step_end

ShrineOfProsperityPast_Movement_AnabelWalkOffScreen:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ShrineOfProsperitPast_Text_AnabelCompanionArrived:
	.string "My companion has arrived, sir.\$"

ShrineOfProsperityPast_Text_OratorWonderful:
	.string "Wonderful…\p"
	.string "I hope you are doing well?$"

ShrineOfProsperityPast_Text_LookerAsWellAsICouldBe:
	.string "About as well as I could be.$"

ShrineOfProsperityPast_Text_AnabelWereHere:
	.string "We were told by Camilla to come here to\n"
	.string "learn why a wicked storm rolled in and\l"
	.string "sent the wild Pokémon in a frenzy.$"

ShrineOfProsperityPast_Text_OratorMustBeTornThund:
	.string "Hmm…\p"
	.string "I assume you must be from another time?\n"
	.string "'Tis a frequent occurance.\p"
	.string "As for the storm…\p"
	.string "It can only be that the spirit of wind\n"
	.string "and the spirit of storms are rampaging…$"

ShrineOfProsperityPast_Text_LookerSpiritsOfWindAndStorms:
	.string "The spirits of wind and storms?$"

ShrineOfProsperityPast_Text_OratorYesTheSpirits:
	.string "Legend has it that they once ruled the\n"
	.string "territory which Porta Bella has now\l"
	.string "settled on.$"

ShrineOfProsperityPast_Text_AnabelWhatHappened:
	.string "Ruled the territory?\p"
	.string "What stopped them? What happened for them\n"
	.string "to cede the territory to the humans?\p"
	.string "Who even ARE these spirits?$"

ShrineOfProsperityPast_Text_OratorStartFromBeginning:
	.string "Ah, so you are entirely unfamiliar…\n"
	.string "Let us start from the beginning, then.$"

ShrineOfProsperityPast_Text_OratorThisIsALegend:
	.string "This is a legend which spans thousands\n"
	.string "of years, back to the founding of this\l"
	.string "town…$"

ShrineOfProsperityPast_Text_AnabelSoTheSpiritsAre:
	.string "So a storm of that ferocity could only\n"
	.string "be caused by a fight between Tornadus\l"
	.string "and Thundurus…$"

ShrineOfProsperityPast_Text_AnabelIllHeadBackWithEstella:
	.string "Looker, I'm going to head back to the\n"
	.string "future now with Estella.\p"
	.string "Be sure to meet up with her parents. I'm\n"
	.string "sure they'll want to show their gratitude.$"

ShrineOfProsperityPast_Text_LookerIWill:
	.string "I will.$"

ShrineOfProsperityPast_Text_Orator:
	.string "Please, return to your time and\n"
	.string "restore balance to Portabella.\p"
	.string "Something must have happened to\n"
	.string "Landorus in the future.$"