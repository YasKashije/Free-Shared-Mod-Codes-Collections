//Game: Army Heroes
//Version: 0.4.1
//APK: https://apkcombo.com/army-heroes/com.progressgames.army.heroes/download/zip

//Namespace: LongAutumn.Framework.Data.Properties
//Class: CurrencyProperty
//Unlimited money
public int Second
{
	get
	{
		return 999999999;
	}
}
		
//Class: Tpc
//1 hit - God mode
private void OnDamageTaken(float amount)
{
	if (this.IsEnemy)
	{
		this.SetDead();
	}
}
		
//Class: ExtendedListenersButton
private float longEnoughHoldTime = 1f;