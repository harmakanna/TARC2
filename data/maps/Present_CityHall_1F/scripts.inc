Present_CityHall_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_CityHall_1F_EventScript_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Present_CityHall_1F_EventScript_OnFrame
	.byte 0

Present_CityHall_1F_EventScript_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 1, Present_CityHall_1F_EventScript_PlaceNPCsForCutscene
	call_if_eq VAR_CUTSCENE_STATE, 2, Present_CityHall_1F_EventScript_PlaceNPCsInside
	end

Present_CityHall_1F_EventScript_PlaceNPCsInside::
	setobjectxyperm LOCALID_CITYHALL_1F_CONCERNED_DAD, 8, 7
	setobjectxyperm LOCALID_CITYHALL_1F_MAYOR, 7, 5
	return

Present_CityHall_1F_EventScript_PlaceNPCsForCutscene::
	setobjectxyperm LOCALID_CITYHALL_1F_ANABEL, 9, 8
	setobjectmovementtype LOCALID_CITYHALL_1F_ANABEL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_CITYHALL_1F_MAYOR, 7, 5
	return

Present_CityHall_1F_EventScript_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 1, Present_CityHall_1F_EventScript_PostStormDiscussion
	.2byte 0

Present_CityHall_1F_EventScript_PostStormDiscussion::
	lockall
	applymovement LOCALID_CITYHALL_1F_MAYOR, Present_CityHall_1F_Movement_MayorPacing1
	playse SE_LEDGE
	msgbox Present_CityHall_1F_Text_MayorOhDear, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_CITYHALL_1F_MAYOR, Present_CityHall_1F_Movement_MayorPacing2
	playse SE_LEDGE
	msgbox Present_CityHall_1F_Text_MayorOhDearOhDear, MSGBOX_DEFAULT
	closemessage
	delay 40
	playse SE_PIN
	applymovement LOCALID_CITYHALL_1F_MAYOR, Present_CityHall_1F_Movement_MayorStartled
	waitmovement 0
	delay 32
	msgbox Present_CityHall_1F_Text_MayorOhHeavens, MSGBOX_DEFAULT
	delay 10
	closemessage
	applymovement LOCALID_CITYHALL_1F_MAYOR, Present_CityHall_1F_Movement_MayorWalkToLooker
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_WalkUp2
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp2
	waitmovement 0
	msgbox Present_CityHall_1F_Text_MayorAreYouAlright, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox Present_CityHall_1F_Text_LookerYoureTheMayor, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_1F_MAYOR, Common_Movement_WalkInPlaceFasterDown
	msgbox Present_CityHall_1F_Text_MayorIAmTheMayor, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_WalkInPlaceFasterUp
	msgbox Present_CityHall_1F_Text_AnabelWhatWasThat, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox Present_CityHall_1F_Text_LookerDocilePokemon, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_WalkInPlaceFasterLeft
	msgbox Present_CityHall_1F_Text_AnabelButThatDoesntHoldUp, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_FaceUp
	applymovement LOCALID_CITYHALL_1F_MAYOR, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Present_CityHall_1F_Text_MayorYouDontSuppose, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_FaceLeft
	msgbox Present_CityHall_1F_Text_LookerHmm, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_CITYHALL_1F_CONCERNED_DAD
	delay 50
	playse SE_DOOR
	addobject LOCALID_CITYHALL_1F_CONCERNED_DAD
	delay 40
	msgbox Present_CityHall_1F_Text_DadHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_FaceDown
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Present_CityHall_1F_Movement_FranticDad
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_WalkUp
	waitmovement 0
	msgbox Present_CityHall_1F_Text_LookerWhatsTheMatter, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_WalkInPlaceFasterUp
	msgbox Present_CityHall_1F_Text_DadMyDaughter, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox Present_CityHall_1F_Text_LookerSlowDown, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_WalkInPlaceFasterDown
	msgbox Present_CityHall_1F_Text_AnabelItsOkay
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_WalkInPlaceFasterUp
	msgbox Present_CityHall_1F_Text_DadThankYouLong, MSGBOX_DEFAULT
	closemessage
	playse SE_REPEL
	waitse
	delay 10
	msgbox Present_CityHall_1F_Text_LookerUsedTheRepel, MSGBOX_DEFAULT
	delay 48
	closemessage
	delay 16
	applymovement LOCALID_CITYHALL_1F_CONCERNED_DAD, Common_Movement_WalkInPlaceFasterUp
	msgbox Present_CityHall_1F_Text_DadWeLiveNear, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_CITYHALL_1F_ANABEL, Common_Movement_WalkInPlaceFasterLeft
	msgbox Present_CityHall_1F_Text_AnabelLostChild
	closemessage
	setvar VAR_CUTSCENE_STATE, 2
	setflag FLAG_SYS_DISABLE_ENCOUNTERS
	setfollowernpc LOCALID_CITYHALL_1F_ANABEL, FNPC_NONE, Present_CityHall_1F_EventScript_AnabelFollower
	releaseall
	end

Present_CityHall_1F_Movement_MayorPacing1:
	jump_in_place_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Present_CityHall_1F_Movement_MayorPacing2:
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
	msgbox Present_CityHall_1F_Text_DadThankYou, MSGBOX_NPC
	end

Present_CityHall_1F_EventScript_Mayor::
	msgbox Present_CityHall_1F_Text_MayorStaySafe, MSGBOX_NPC
	end

Present_CityHall_1F_EventScript_AnabelFollower::
    goto_if_set FLAG_STEPPED_OUT_OF_CITY_HALL, Present_CityHall_1F_EventScript_AnabelLockedDoors
    msgbox Present_CityHall_1F_Text_AnabelFollowerLetsFindHer, MSGBOX_NPC
    end

Present_CityHall_1F_EventScript_AnabelLockedDoors::
    msgbox Present_CityHall_1F_Text_AnabelFollowerItSeemsEverybody, MSGBOX_NPC
    end

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
	.string "Looker: We made it out okay.\p"
	.string "If I understand correctly, you must be\n"
	.string "the mayor of Porto Bella?$"

Present_CityHall_1F_Text_MayorIAmTheMayor:
	.string "Oh heavens, my apologies!\p"
	.string "I am Mayor Morrigan!\p"
	.string "Mayor: I hoped to greet you at the port,\n"
	.string "but I was bogged down by endless\l"
	.string "paperwork!$"

Present_CityHall_1F_Text_AnabelWhatWasThat:
	.string "Anabel: As we all are.\p"
	.string "Enough of the formalities, though.\n"
	.string "What the heck was that?$"

Present_CityHall_1F_Text_LookerDocilePokemon:
	.string "Looker: Pokémon in this area are known\n"
	.string "for their docility due to the climate.\p"
	.string "It stands to reason the sudden storm\n"
	.string "has the wildlife agitated.$"
	
Present_CityHall_1F_Text_AnabelButThatDoesntHoldUp:
	.string "Anabel: But this region gets slammed\n"
	.string "by storms for half the year.\p"
	.string "From the speed and ferocity it rolled\n"
	.string "in, this does not seem natural at all.$"

Present_CityHall_1F_Text_MayorYouDontSuppose:
	.string "Mayor: Oh me, you don't suppose Team\n"
	.string "Aqua is up to no good again?\p"
	.string "Those goons moved in not long ago\n"
	.string "and now the whole city is on edge!$"

Present_CityHall_1F_Text_AnabelFollowerLetsFindHer:
    .string "Looker, let's find that man's kid\n"
    .string "and make sure she returns home safe!$"

Present_CityHall_1F_Text_AnabelFollowerItSeemsEverybody:
    .string "It seems everybody fled inside and\n"
    .string "shut their doors with all the chaos…\p"
    .string "Once we find that man's child, let's\n"
    .string "get to the bottom of this mystery!$"

Present_CityHall_1F_Text_LookerHmm:
	.string "Looker: Hmm…$"

Present_CityHall_1F_Text_DadHelpMe:
	.string "Help! Somebody help!$"

Present_CityHall_1F_Text_LookerWhatsTheMatter:
	.string "Looker: Sir, what seems to be the\n"
	.string "matter?$"

Present_CityHall_1F_Text_DadMyDaughter:
	.string "Man: My daughter!\n"
	.string "Estella!\p"
	.string "When the storm started, she slipped out\n"
	.string "of the house and ran to the woods!\p"
	.string "I swear, her old looney grandmother's\n"
	.string "putting crazy ideas in her head about\l"
	.string "gods and that old Shrine in the forest\l"
	.string "and forgetting to respect nature…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "You look like a police officer, could\n"
	.string "you please go out and find her?\p"
	.string "I'm begging you!$"

Present_CityHall_1F_Text_LookerSlowDown:
	.string "Looker: Slow down.\p"
	.string "We can find your daughter for you.$"

Present_CityHall_1F_Text_AnabelItsOkay:
	.string "Anabel: Don't worry!\p"
	.string "When Looker's on the hunt, there isn't\n"
	.string "anyone who can shake his tail!$"

Present_CityHall_1F_Text_DadThankYouLong:
	.string "Man: Oh, thank you!\p"
	.string "Here, I brought repels to make my\n"
	.string "way through the city.\p"
	.string "Spray some of this on!$"

Present_CityHall_1F_Text_LookerUsedTheRepel:
	.string "Looker used the repels.$"

Present_CityHall_1F_Text_DadWeLiveNear:
	.string "Man: We live near the western forest.\n"
	.string "I'm sure she snuck away there!$"

Present_CityHall_1F_Text_AnabelLostChild:
	.string "Anabel: Alright, the case of the sudden\n"
	.string "storm can wait a bit.\p"
	.string "Looker, we have a lost child to find!$"

Present_CityHall_1F_Text_DadThankYou:
	.string "Oh, thank you!\p"
	.string "We live near the western forest.\n"
	.string "I'm sure she snuck away there!$"