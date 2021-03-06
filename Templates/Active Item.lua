-------------------------------------------------------------------------------
--
-- This script provides the basic implementation for an active item.
-- The item will spawn the podestal item "Breakfast" near the player when used.
--
-------------------------------------------------------------------------------


-- Replace the parameter with your own item name
local itemId = Isaac.GetItemIdByName("Mod Active 1")
if itemId == -1 then
	-- Don't do stuff when the item wasn't found
	Game():GetPlayer(0):AnimateSad()
	return;
end

-- Register our mod callback for the use with BrokenRemote
function mod:MC_USE_ITEM(id, rng)
	if id ~= itemId then
		return
	end
	
	local p = Game():GetPlayer(0)
	local r = Game():GetRoom()

	pos = r:FindFreePickupSpawnPosition(p.Position, 1.0, true)

	-- Spawn the item
	Isaac.Spawn(
		EntityType.ENTITY_PICKUP,
		PickupVariant.PICKUP_COLLECTIBLE,
		CollectibleType.COLLECTIBLE_BREAKFAST,
		pos,
		Vector(0,0),
		nil)
	
end