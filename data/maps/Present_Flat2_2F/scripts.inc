Present_Flat2_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_Flat2_2F_OnTransition
	.byte 0

Present_Flat2_2F_OnTransition:
	returnqueststate QUEST_SMEARGLE
	call_if_ge QUEST_SMEARGLE, 3, Present_Flat2_2F_CheckArtist
	end

Present_Flat2_2F_CheckArtist::
	call_if_unset FLAG_HIDE_INSIDE_OUTSIDE_NPCS, Present_Flat2_2F_SetUpArtist
	return

Present_Flat2_2F_SetUpArtist::
	setobjectmovementtype LOCALID_INSIDE_ARTIST, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_INSIDE_ARTIST, 6, 5
	return
	