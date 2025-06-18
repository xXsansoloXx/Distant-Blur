#include "PCH.h"
#include "logger.h"
#include "MCP.h"

void OnMessage(SKSE::MessagingInterface::Message* message) {
	// Handle messages from SKSE called in order of first to last occurance
    if (message->type == SKSE::MessagingInterface::kPostLoad) {
		// Called after all skse plugins have loaded and sent to registered plugins once all plugins have been loaded
    }
    if (message->type == SKSE::MessagingInterface::kPostPostLoad) {
		// Called immediately after all plugins have loaded and is useful for debugging skse plugin incompatibilities
        // Sent right after kPostLoad to facilitate the correct dispatching/registering of messages/listeners
        logger::info("PostPostLoad message received");
    }
    if (message->type == SKSE::MessagingInterface::kPreLoadGame) {
		// message->dataLen: length of file path, data: char* file path of .ess savegame file
        // sent immediately before savegame is read
    }
    if (message->type == SKSE::MessagingInterface::kPostLoadGame) {
        // Post-load game, sent after an attempt to load a saved game has finished
    }
    if (message->type == SKSE::MessagingInterface::kSaveGame) {
		// Called when a save is created
    }
    if (message->type == SKSE::MessagingInterface::kDeleteGame) {
		// Sent right before deleting the .skse cosave and the .ess save
    }
    if (message->type == SKSE::MessagingInterface::kInputLoaded) {
        // Sent right after game input is loaded, right before the main menu initializes
    }
    if (message->type == SKSE::MessagingInterface::kNewGame) {
        // Sent after a new game is created, before the game has loaded
    }
    if (message->type == SKSE::MessagingInterface::kDataLoaded) {
        // Sent after the data handler has loaded all its forms
    }

}

SKSEPluginLoad(const SKSE::LoadInterface *skse) {

    SetupLog();
    logger::info("Plugin loaded");
    SKSE::Init(skse);
    SKSE::GetMessagingInterface()->RegisterListener(OnMessage);
    MCP::Register();
    return true;
}
