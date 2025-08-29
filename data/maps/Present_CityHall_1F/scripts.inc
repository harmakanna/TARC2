Present_CityHall_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_CityHall_1F_EventScript_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Present_CityHall_1F_EventScript_OnFrame
	.byte 0

Present_CityHall_1F_EventScript_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 3, Present_CityHall_1F_EventScript_PlaceNPCsForCutscene
	call_if_eq VAR_CUTSCENE_STATE, 4, Present_CityHall_1F_EventScript_PlaceNPCsInside
	end

Present_CityHall_1F_EventScript_PlaceNPCsInside::
	setobjectxyperm LOCALID_CITYHALL_1F_CONCERNED_DAD, 7, 5
	setobjectxyperm LOCALID_CITYHALL_1F_MAYOR, 8, 5
	return

Present_CityHall_1F_EventScript_PlaceNPCsForCutscene::
	setobjectxyperm LOCALID_CITYHALL_1F_ANABEL, 9, 8
	setobjectmovementtype LOCALID_CITYHALL_1F_ANABEL, MOVEMENT_TYPE_INVISIBLE
	setobjectxyperm LOCALID_CITYHALL_1F_MAYOR, 7, 5
	return

Present_CityHall_1F_EventScript_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 3, Present_CityHall_1F_EventScript_PostStormDiscussion
	.2byte 0

Present_CityHall_1F_EventScript_PostStormDiscussion::
	lockall
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	special	SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
	waitmovement 0
	delay 10
	applymovement LOCALID_CITYHALL_1F_MAYOR, Present_CityHall_1F_Movement_MayorPacing1
	playse SE_LEDGE
	speakername Name_Unknown
	message Present_CityHall_1F_Text_MayorOhDear
	waitmessage
	delay 80
	closemessage
	delay 40
	applymovement LOCALID_CITYHALL_1F_MAYOR, Present_CityHall_1F_Movement_MayorPacing2
	speakername Name_Unknown
	message Present_CityHall_1F_Text_MayorOhDearOhDear
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	delay 80
	closemessage
	delay 120
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_SetVisibleFaceUp
	applymovement LOCALID_PLAYER, Common_Movement_SetVisible
	playse SE_EXIT
	waitse
	playse SE_PIN
	applymovement LOCALID_CITYHALL_1F_MAYOR, Present_CityHall_1F_Movement_MayorStartled
	waitmovement 0
	delay 32
	speakername Name_Unknown
	message Present_CityHall_1F_Text_MayorOhHeavens
	waitmessage
	delay 80
	closemessage
	playbgm MUS_PL_LOOKER, FALSE
	delay 40
	applymovement LOCALID_CITYHALL_1F_MAYOR, Present_CityHall_1F_Movement_MayorWalkToLooker
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_WalkUp2
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp2
	waitmovement 0
	speakername Name_Unknown
	msgbox Present_CityHall_1F_Text_MayorAreYouAlright, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_CityHall_1F_Text_LookerYoureTheMayor
	speakername Name_Unknown
	applymovement LOCALID_CITYHALL_1F_MAYOR, Common_Movement_WalkInPlaceFasterDown
	msgbox Present_CityHall_1F_Text_MayorIAmTheMayor, MSGBOX_DEFAULT
	speakername Name_Mayor
	msgbox Present_CityHall_1F_Text_MayorMorrigan, MSGBOX_DEFAULT
	speak LOCALID_CITYHALL_1F_ANABEL, DIR_NORTH, Name_Anabel, Present_CityHall_1F_Text_AnabelWhatWasThat
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_WalkInPlaceFasterLeft
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_CityHall_1F_Text_LookerDocilePokemon
	speak LOCALID_CITYHALL_1F_ANABEL, DIR_WEST, Name_Anabel, Present_CityHall_1F_Text_AnabelButThatDoesntHoldUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_FaceUp
	speak LOCALID_CITYHALL_1F_MAYOR, DIR_SOUTH, Name_Mayor, Present_CityHall_1F_Text_MayorYouDontSuppose
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_FaceLeft
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_CityHall_1F_Text_LookerHmm
	closemessage
	clearflag FLAG_HIDE_CITYHALL_1F_CONCERNED_DAD
	delay 50
	playse SE_DOOR
	addobject LOCALID_CITYHALL_1F_CONCERNED_DAD
	delay 40
	msgbox Present_CityHall_1F_Text_DadHelpMe, MSGBOX_DEFAULT
	delay 32
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_FaceDown
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_FaceLeft
	waitmovement 0
	delay 50
	playse SE_PIN
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_FaceUpExclamationMark
	waitmovement 0
	delay 48
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_WalkUp
	waitmovement 0
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, Present_CityHall_1F_Text_LookerWhatsTheMatter
	speak LOCALID_CITYHALL_1F_CONCERNED_DAD, DIR_NORTH, Name_Concerned_Dad, Present_CityHall_1F_Text_DadMyDaughter
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, Present_CityHall_1F_Text_LookerSlowDown
	speak LOCALID_CITYHALL_1F_ANABEL, DIR_SOUTH, Name_Anabel, Present_CityHall_1F_Text_AnabelItsOkay
	speak LOCALID_CITYHALL_1F_CONCERNED_DAD, DIR_NORTH, Name_Concerned_Dad, Present_CityHall_1F_Text_DadThankYouLong
	closemessage
	playse SE_REPEL
	waitse
	delay 40
	message Present_CityHall_1F_Text_LookerUsedTheRepel
	waitmessage
	delay 50
	closemessage
	delay 30
	speak LOCALID_CITYHALL_1F_CONCERNED_DAD, DIR_NORTH, Name_Concerned_Dad, Present_CityHall_1F_Text_DadWeLiveNear
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_CITYHALL_1F_ANABEL, DIR_WEST, Name_Anabel, Present_CityHall_1F_Text_AnabelLostChild
	closemessage
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Present_CityHall_1F_Movement_DadGetOutOfWay
	waitmovement 0
	clearflag FLAG_SYS_SPAWN_INVISIBLE
	setvar VAR_CUTSCENE_STATE, 4
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setfollowernpc LOCALID_CITYHALL_1F_ANABEL, FNPC_ALL_LAND, Present_CityHall_1F_EventScript_AnabelFollower
	special RemoveCameraObject
	startquest QUEST_SAVE_ESTELLA
	releaseall
	end

Present_CityHall_1F_Movement_DadGetOutOfWay:
	walk_left
	walk_up
	walk_up
	step_end

Present_CityHall_1F_Movement_MayorPacing1:
	jump_in_place_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Present_CityHall_1F_Movement_MayorPacing2:
	jump_in_place_left
	jump_in_place_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Present_CityHall_1F_Movement_MayorStartled:
	face_down
	emote_exclamation_mark 
	step_end

Present_CityHall_1F_Movement_MayorWalkToLooker:
	walk_fast_right
	face_down
	step_end

Present_CityHall_1F_Movement_FranticDad:
	face_right
	delay_8
	face_left
	delay_16
	face_right
	delay_8
	face_up
	step_end

Present_CityHall_1F_EventScript_ConcernedDad::
	lock
	faceplayer
	speakername Name_Concerned_Dad
	msgbox Present_CityHall_1F_Text_DadThankYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_FaceUp
	waitmovement 0
	release
	end

Present_CityHall_1F_EventScript_Mayor::
	speakername Name_Mayor
	msgbox Present_CityHall_1F_Text_MayorStaySafe, MSGBOX_NPC
	end

Present_CityHall_1F_EventScript_AnabelFollower::
    goto_if_set FLAG_STEPPED_OUT_OF_CITY_HALL, Present_CityHall_1F_EventScript_AnabelLockedDoors
	speakername Name_Anabel
    msgbox Present_CityHall_1F_Text_AnabelFollowerLetsFindHer, MSGBOX_NPC
    end

Present_CityHall_1F_EventScript_AnabelLockedDoors::
	speakername Name_Anabel
    msgbox Present_CityHall_1F_Text_AnabelFollowerItSeemsEverybody, MSGBOX_NPC
    end

Present_CityHall_1F_EventScript_TuskFossilDisplay::
	lock
	goto_if_set FLAG_CHOSE_TUSK_FOSSIL, Present_CityHall_1F_EventScript_EmptyDisplay
	showmonpic SPECIES_SQUIRTLE, 10, 3
	msgbox Present_CityHall_1F_Text_TuskFossilDisplay, MSGBOX_SIGN
	closemessage
	hidemonpic
	release
	end
	
Present_CityHall_1F_EventScript_WingFossilDisplay::
	lock
	goto_if_set FLAG_CHOSE_WING_FOSSIL, Present_CityHall_1F_EventScript_EmptyDisplay
	showmonpic SPECIES_CHARMANDER, 10, 3
	msgbox Present_CityHall_1F_Text_WingFossilDisplay, MSGBOX_SIGN
	closemessage
	hidemonpic
	release
	end

Present_CityHall_1F_EventScript_EmptyDisplay::
	msgbox Present_CityHall_1F_Text_EmptyDisplay, MSGBOX_SIGN
	closemessage
	release
	end

Present_CityHall_1F_EventScript_EmployeeStairs::
	msgbox Present_CityHall_1F_Text_EmployeeStairs, MSGBOX_NPC 
	end

Present_CityHall_1F_EventScript_EmployeeCounter::
	lock
	speak LOCALID_CITYHALL_1F_COUNTEREMPLOYEE, DIR_SOUTH, NULL, Present_CityHall_1F_Text_EmployeeCounter
	closemessage
	release
	end

Present_CityHall_1F_Text_EmployeeCounter:
	.string "Welcome to Porta Bella City, the\n"
	.string "city of progress!\p"
	.string "I hope you enjoy your time here!$"

Present_CityHall_1F_Text_EmployeeStairs:
	.string "I'm sorry.\p"
	.string "The mayor is currently busy with\n"
	.string "official responsibilities.\p"
	.string "Please come back later.$"

Present_CityHall_1F_Text_TuskFossilDisplay:
	.string "A regal-looking tusk eroded over\n"
	.string "hundreds of years.\p"
	.string "Thought to belong to a species\n"
	.string "related to pigs.\p"
	.string "Generously donated by Everett.$"

Present_CityHall_1F_Text_WingFossilDisplay:
	.string "A translucent-looking wing imprint\n"
	.string "fossilized in sediment.\p"
	.string "Thought to belong to a species\n"
	.string "related to dragonflies.\p"
	.string "Generously donated by Everett.$"

Present_CityHall_1F_Text_EmptyDisplay:
	.string "An empty display.\p"
	.string "City Hall will kindly accept all\n"
	.string "donations of fossils.$"

Present_CityHall_1F_Text_MayorStaySafe:
	.string "Oh heavens!\n"
	.string "Stay safe out there you two!\p"
	.string "There's no telling what could happen\n"
	.string "out in that forest!$"

Present_CityHall_1F_Text_MayorOhDear:
	.string "Oh dear…$"

Present_CityHall_1F_Text_MayorOhDearOhDear:
	.string "Oh dear, oh dear,\n"
	.string "oh dear…$"

Present_CityHall_1F_Text_MayorOhHeavens:
	.string "Oh, heavens!$"

Present_CityHall_1F_Text_MayorAreYouAlright:
	.string "Anabel, Looker, are you\n"
	.string "two okay?\p"
	.string "What horrible timing!\p"
	.string "We were forecasted to be sunny and\n"
	.string "bright for the next two weeks!$"

Present_CityHall_1F_Text_LookerYoureTheMayor:
	.string "We made it out okay.\p"
	.string "If I understand correctly, you must be\n"
	.string "the mayor of Porta Bella?$"

Present_CityHall_1F_Text_MayorIAmTheMayor:
	.string "Oh heavens, my apologies!\p"
	.string "I am Mayor Morrigan!$"

Present_CityHall_1F_Text_MayorMorrigan:
	.string "I hoped to greet you at the port, but I\n"
	.string "was bogged down by endless paperwork!$"

Present_CityHall_1F_Text_AnabelWhatWasThat:
	.string "As we all are.\p"
	.string "Enough of the formalities, though.\n"
	.string "What the heck was that?$"

Present_CityHall_1F_Text_LookerDocilePokemon:
	.string "Pokémon in this area are known for\n"
	.string "their docility due to the climate.\p"
	.string "It stands to reason the sudden storm\n"
	.string "has the wildlife agitated.$"
	
Present_CityHall_1F_Text_AnabelButThatDoesntHoldUp:
	.string "But this region gets slammed by storms\n"
	.string "for half the year.\p"
	.string "From the speed and ferocity it rolled\n"
	.string "in, this does not seem natural at all.$"

Present_CityHall_1F_Text_MayorYouDontSuppose:
	.string "Oh me, you don't suppose Team Aqua is\n"
	.string "up to no good again?\p"
	.string "Those goons moved in not long ago and\n"
	.string "now the whole city is on edge!$"

Present_CityHall_1F_Text_AnabelFollowerLetsFindHer:
    .string "Looker, let's find that man's kid and\n"
    .string "make sure she returns home safe!$"

Present_CityHall_1F_Text_AnabelFollowerItSeemsEverybody:
    .string "It seems everybody fled inside and\n"
    .string "shut their doors with all the chaos…\p"
    .string "Once we find that man's child, let's\n"
    .string "get to the bottom of this mystery!$"

Present_CityHall_1F_Text_LookerHmm:
	.string "Hmm…$"

Present_CityHall_1F_Text_DadHelpMe:
	.string "Help! Somebody help!$"

Present_CityHall_1F_Text_LookerWhatsTheMatter:
	.string "Sir, what seems to be the\n"
	.string "matter?$"

Present_CityHall_1F_Text_DadMyDaughter:
	.string "My daughter!\n"
	.string "Estella!\p"
	.string "When the storm started, she slipped out\n"
	.string "of the house and ran to the woods!\p"
	.string "I swear, her old looney grandmother's\n"
	.string "putting crazy ideas in her head about\l"
	.string "spirits and those old Shrines in the\l"
	.string "forest and forgetting our origins…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "You look like a police officer, could\n"
	.string "you please go out and find her?\p"
	.string "I'm begging you!$"

Present_CityHall_1F_Text_LookerSlowDown:
	.string "Slow down.\p"
	.string "We can find your daughter for you.$"

Present_CityHall_1F_Text_AnabelItsOkay:
	.string "Don't worry!\p"
	.string "When Looker's on the hunt, there isn't\n"
	.string "anyone who can shake his tail!$"

Present_CityHall_1F_Text_DadThankYouLong:
	.string "Oh, thank you!\p"
	.string "Here, I brought repels to make my way\n"
	.string "through the city.\p"
	.string "Spray some of this on!$"

Present_CityHall_1F_Text_LookerUsedTheRepel:
	.string "Looker used the repels.$"

Present_CityHall_1F_Text_DadWeLiveNear:
	.string "We live near the western forest.\n"
	.string "I'm sure she snuck away there!$"

Present_CityHall_1F_Text_AnabelLostChild:
	.string "Alright, the case of the sudden storm\n"
	.string "can wait a bit.\p"
	.string "Looker, we have a lost child to find!$"

Present_CityHall_1F_Text_DadThankYou:
	.string "Oh, thank you!\p"
	.string "We live near the western forest.\n"
	.string "I'm sure she snuck away there!$"