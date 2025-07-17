Present_CityHall_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_CityHall_1F_EventScript_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Present_CityHall_1F_EventScript_OnFrame
	.byte 0

Present_CityHall_1F_EventScript_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 1, Present_CityHall_1F_EventScript_PlaceNPCsForCutscene
	end

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
	msgbox Present_CityHall_1F_Text_MayorOhDear, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_1F_MAYOR, Common_Movement_Delay32
	waitmovement 0
	closemessage
	applymovement LOCALID_CITYHALL_1F_MAYOR, Present_CityHall_1F_Movement_MayorPacing2
	msgbox Present_CityHall_1F_Text_MayorOhDearOhDear, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_1F_MAYOR, Common_Movement_Delay32
	waitmovement 0
	closemessage
	playse SE_PIN
	applymovement LOCALID_CITYHALL_1F_MAYOR, Present_CityHall_1F_Movement_MayorStartled
	waitmovement 0
	msgbox Present_CityHall_1F_Text_MayorOhHeavens, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_1F_MAYOR, Common_Movement_Delay32
	waitmovement 0
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
	setvar VAR_CUTSCENE_STATE, 2
	setfollowernpc LOCALID_CITYHALL_1F_ANABEL, FNPC_NONE, 0
	releaseall
	end

Present_CityHall_1F_Movement_MayorPacing1:
	jump_in_place_right
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
	.string "We were forecasted to be sunny\n"
	.string "and bright for the next two weeks!$"

Present_CityHall_1F_Text_LookerYoureTheMayor:
	.string "Looker: We made it out okay.\p"
	.string "If I understand correctly, you\n"
	.string "must be the mayor of Porto Bella?$"

Present_CityHall_1F_Text_MayorIAmTheMayor:
	.string "Mayor: Oh heavens, my apologies!\p"
	.string "I am Mayor Morrigan!\p"
	.string "I hoped to greet you at the port,\n"
	.string "but I was bogged down by\l"
	.string "endless paperwork!$"

Present_CityHall_1F_Text_AnabelWhatWasThat:
	.string "Anabel: As we all are.\n"
	.string "Enough of the formalities,\p"
	.string "what the heck was that?$"

Present_CityHall_1F_Text_LookerDocilePokemon:
	.string "Looker: Pokémon in this part of\n"
	.string "the country are known for their\l"
	.string "docility due to the climate.\p"
	.string "It stands to reason the sudden\n"
	.string "storm has the wildlife agitated.$"
	
Present_CityHall_1F_Text_AnabelButThatDoesntHoldUp:
	.string "Anabel: But this region gets hit\n"
	.string "with storms for half the year.\p"
	.string "Based on the speed and ferocity\n"
	.string "it rolled in, this does not seem\l"
	.string "natural at all.$"

Present_CityHall_1F_Text_MayorYouDontSuppose:
	.string "Mayor: Oh me, you don't suppose\n"
	.string "Team Aqua is up to no good again?\p"
	.string "Those goons moved in not long ago\n"
	.string "and has the whole city on edge!$"

Present_CityHall_1F_Text_LookerHmm:
	.string "Looker: Hmm…$"



