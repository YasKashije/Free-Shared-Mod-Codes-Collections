//Game: Space Armada: Galaxy Wars
//Version: 2.1.420
//APK: https://play.google.com/store/apps/details?id=com.CubeSoftware.SpaceConflictGame

//CurrencyBehaviour
	public bool HaveMoneyForCost(CurrencyCost cost)
	{
		return true;
	}

	public bool HaveMoneyForCost(CurrencyType type, ObscuredInt cost)
	{
		return true;
	}

	public bool HaveMoneyForProperty(PropertyDef def)
	{
		return true;
	}
	
//Profile
public bool HaveMoneyForItem(ShopItem item)
		{
		}
		
		public bool HaveMoney(int price, CurrencyType currency)
		{
		}

		[Address(RVA = "0x5FCA74", Offset = "0x5FCA74")]
		public bool HaveMoney(CurrencyCost cost)
		{
		}
		
public bool Banned
{
	[Address(RVA = "0x60A284", Offset = "0x60A284")]
	get
	{
	}
	[Address(RVA = "0x60A28C", Offset = "0x60A28C")]
	private set
	{
	}
}

public bool IsCheater
{
	[Address(RVA = "0x60A2A4", Offset = "0x60A2A4")]
	get
	{
	}
	[Address(RVA = "0x60A2AC", Offset = "0x60A2AC")]
	private set
	{
	}
}
