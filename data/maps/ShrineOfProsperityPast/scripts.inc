ShrineOfProsperityPast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShrineOfProsperityPast_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShrineOfProsperityPast_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, ShrineOfProsperityPast_OnResume
	.byte 0

ShrineOfProsperityPast_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 10, ShrineOfProsperityPast_EventScript_SetupMyth
	call_if_eq VAR_CUTSCENE_STATE, 11, ShrineOfProsperityPast_EventScript_SetupMythReturn
	end

ShrineOfProsperityPast_EventScript_SetupMyth::
	setobjectmovementtype LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, MOVEMENT_TYPE_FACE_LEFT
	return

ShrineOfProsperityPast_EventScript_SetupMythReturn::
	setobjectmovementtype LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, MOVEMENT_TYPE_FACE_DOWN
	return

ShrineOfProsperityPast_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 11, ShrineOfProsperityPast_EventScript_EndLandorusMyth
	.2byte 0

ShrineOfProsperityPast_OnResume:
	special HealPlayerParty
	end
	
ShrineOfProsperityPast_EventScript_VillageOrator::
	msgbox ShrineOfProsperityPast_Text_OratorPleaseReturn, MSGBOX_NPC
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
	speak LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, DIR_SOUTH, Name_Anabel, ShrineOfProsperityPast_Text_AnabelCompanionArrived
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, Common_Movement_FaceDown
	speak LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, DIR_SOUTH, Name_Orator, ShrineOfProsperityPast_Text_OratorWonderful
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, ShrineOfProsperityPast_Text_LookerAsWellAsICouldBe
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, Common_Movement_FaceLeft
	speak LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, DIR_EAST, Name_Anabel, ShrineOfProsperityPast_Text_AnabelWereHere
	speak LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, DIR_WEST, Name_Orator, ShrineOfProsperityPast_Text_OratorMustBeTornThund
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, Common_Movement_FaceDown
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, Common_Movement_FaceDown
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, ShrineOfProsperityPast_Text_LookerSpiritsOfWindAndStorms
	speak LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, DIR_SOUTH, Name_Orator, ShrineOfProsperityPast_Text_OratorYesTheSpirits
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, ShrineOfProsperityPast_Text_LookerWhatHappened
	speak LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, DIR_SOUTH, Name_Orator, ShrineOfProsperityPast_Text_OratorStartFromBeginning
	closemessage
	delay 40
	fadenewbgm MUS_NONE
	fadescreen FADE_TO_BLACK
	delay 80
	speakername Name_Orator
	msgbox ShrineOfProsperityPast_Text_OratorThisIsALegend, MSGBOX_DEFAULT
	setvar VAR_CUTSCENE_STATE, 11
	setflag FLAG_SYS_SPAWN_INVISIBLE
	setflag FLAG_SYS_PREVENT_MAP_FADE
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	warpsilent MAP_CUTSCENE_MYTH, 14, 14
	waitstate
	end

ShrineOfProsperityPast_EventScript_EndLandorusMyth::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	fadescreen FADE_FROM_BLACK
	delay 40
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, Common_Movement_FaceLeft
	speak LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, DIR_EAST, Name_Anabel, ShrineOfProsperityPast_Text_AnabelSoTheSpiritsAre
	closemessage
	delay 80
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, Common_Movement_FaceDown
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, Common_Movement_FaceDown
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceDownExclamationMark
	delay 60
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, ShrineOfProsperityPast_Text_LookerThisCanOnlyMean
	applymovement LOCALID_PLAYER, ShrineOfProsperityPast_Movement_WalkLeftFaceUp
	waitmovement 0
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, ShrineOfProsperityPast_Text_LookerAnabelWeNeedToGoBack
	speak LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, DIR_SOUTH, Name_Anabel, ShrineOfProsperityPast_Text_AnabelIllHeadBackWithEstella
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, ShrineOfProsperityPast_Text_LookerIWill
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, Common_Movement_FaceRight
	speak LOCALID_SHRINE_PROSPERITY_PAST_ORATOR, DIR_WEST, Name_Orator, ShrineOfProsperityPast_Text_OratorPleaseReturn
	speak LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, DIR_EAST, Name_Anabel, ShrineOfProsperityPast_Text_AnabelWeWill
	closemessage
	applymovement LOCALID_PLAYER, ShrineOfProsperityPast_Movement_LookerWatchAnabelWalkOffScreen
	applymovement LOCALID_SHRINE_PROSPERITY_PAST_ANABEL, ShrineOfProsperityPast_Movement_AnabelWalkOffScreen
	waitmovement 0
	delay 40
	removeobject LOCALID_SHRINE_PROSPERITY_PAST_ANABEL
	playbgm MUS_DP_ETERNA_FOREST, TRUE
	clearflag FLAG_HIDE_SHRINE_PEACE_CELEBI
	clearflag FLAG_LOCK_CITY_DOORS
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	clearflag FLAG_HIDE_CITYHALL_2F_RANGER_HEADRANGER
	setflag FLAG_HIDE_PAST_TOWN_HALL_ESTELLA
	setflag FLAG_HIDE_CITYHALL_1F_CONCERNED_DAD
	setflag FLAG_SYS_MAIN_GAME_START
	setvar VAR_CUTSCENE_STATE, 12
	setvar VAR_PORTO_BELLA_CITY_STATE, 3
	setvar VAR_QUEUE_GENIE_FIGHT, 1
	setvar VAR_PRESENT_GYM_STATE, 1
	questmenu QUEST_MENU_SET_REWARD QUEST_SAVE_ESTELLA
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

ShrineOfProsperityPast_Movement_WalkLeftFaceUp:
	walk_left
	face_up
	step_end

ShrineOfProsperityPast_Movement_LookerWatchAnabelWalkOffScreen:
	delay_16
	face_left
	delay_16
	delay_16
	face_down
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

ShrineOfProsperityPast_Text_AnabelCompanionArrived:
	.string "My companion has arrived, sir.$"

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

ShrineOfProsperityPast_Text_LookerWhatHappened:
	.string "Ruled the territory?\p"
	.string "Who are the spirits? Why did they cede\n"
	.string "the territory to the humans?\p"
	.string "We must learn how to stop these spirits\n"
	.string "if they really caused the storm.$"

ShrineOfProsperityPast_Text_OratorStartFromBeginning:
	.string "Ah, so you are entirely unfamiliar…\n"
	.string "Let us start from the beginning, then.$"

ShrineOfProsperityPast_Text_OratorThisIsALegend:
	.string "This is a legend which spans thousands\n"
	.string "of years, back to the founding of this\l"
	.string "town…$"

ShrineOfProsperityPast_Text_AnabelSoTheSpiritsAre:
	.string "Wow…\p"
	.string "So a storm of that ferocity could only\n"
	.string "be caused by a fight between Tornadus\l"
	.string "and Thundurus…$"

ShrineOfProsperityPast_Text_LookerThisCanOnlyMean:
	.string "This can only mean one thing…\p"
	.string "Landorus has gone missing!$"

ShrineOfProsperityPast_Text_LookerAnabelWeNeedToGoBack:
	.string "Anabel, We need to go back to the future\n"
	.string "and get to the bottom of what happened\l"
	.string "to Porta Bella's Spirit of Prosperity.$"

ShrineOfProsperityPast_Text_AnabelIllHeadBackWithEstella:
	.string "I'm 100 percent with you, Looker.\p"
	.string "I'll rush back to the city proper now\n"
	.string "with Estella.\p"
	.string "Be sure to meet up with her parents.\n"
	.string "They're sure to show their gratitude.$"

ShrineOfProsperityPast_Text_LookerIWill:
	.string "Of course.$"

ShrineOfProsperityPast_Text_OratorPleaseReturn:
	.string "Please, return to your time and\n"
	.string "restore balance to Porta Bella.\p"
	.string "Something must have happened to\n"
	.string "Landorus in the future.$"

ShrineOfProsperityPast_Text_AnabelWeWill:
	.string "We will.$"
