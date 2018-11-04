// m_hammer.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
inherit S_WEAPON;

int duanlian(object weapon);
int do_hui(object weapon);


string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
        add_action("do_duanlian","duanlian");
	add_action("do_hui","hui");
}


void create()
{	
	object me;
	string w_name,w_id,w_or;
	int w_lv;
	me = this_player();
//��������
	w_name=me->query("weapon/name");
	w_id = "my "+me->query("weapon/id");
	w_or = me->query("weapon/or");
	w_lv = me->query("weapon/lv");
        if (!me->query("weapon/name"))
        {
	w_name="���Ƶĸִ�";
        }	
        if (!me->query("weapon/id"))
        {
	w_id="hammer";
        }	
        if (!me->query("weapon/or"))
        {
	w_or="ǧ����ľ";
        }	
        if (!me->query("weapon/lv"))
        {
	w_lv=5;
        }	
        if (me->query("weapon/lv",1) > 150)
        {
	w_lv=150;
        }
	set_name(w_name, ({w_id}));
	set("unit", "��");   
	set("value",0);
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
	set_desc(w_lv,w_or,w_name);
	switch(w_or)
		{
		case "ǧ����ľ" :
			set_weight(500);
			set("material", "iron");
			break;
		case "���׽�ĸ" :
			set_weight(1000);
			set("material", "steel");
			break;
		case "��˿����" :
			set_weight(30);
			set("material", "bamboo");
			break;
		default :
		} 
	if( me->query("weapon/wield_msg"))
		set("wield_msg", me->query("weapon/wield_msg")+"\n");
	else
		set("wield_msg", "$N��������һ����ȡ����һ��"+w_name+"�������С�\n");
	if( me->query("weapon/unwield_msg"))
		set("unwield_msg", me->query("weapon/unwield_msg")+"\n");
	else
		set("unwield_msg", "$N����"+w_name+"������һ��գ�ۼ���Ȼ����Ӱ�١�\n");
	init_hammer(w_lv * 10);
	setup();
}	



int do_duanlian(object weapon)
{
	object me;
	int w_zhi, w_level;
	string w_or;

	me=this_player();
	if( !weapon )
		return notify_fail("��Ҫ����ʲô?\n");

	if( (int)me->query("max_neili") < 10 )
		return notify_fail("��������������޷�����������\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("��������������޷�����������\n");
if (me->is_fighting())
return notify_fail("�������?\n");

if (me->is_busy())
return notify_fail("��æ����?\n");
if (userp(me) && !me->query_skill_mapped("force"))
return notify_fail("��û���ڹ�����ʹ���а�!\n");
	if( me->query_skill("shenzhao-jing", 1) > 100          )
		return notify_fail("���վ����������޷�����������\n");

	if( me->query_skill("shenzhao-jing", 1) > 100
            && (int)me->query("max_neili") < 5000 )
		return notify_fail("��������������޷�����������\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("������������޷�����������\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("�����ڵ�����̫�����޷�����������\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("�����ڵľ����޷����У����ܶ���������\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("���Ǳ�ܲ������޷�����������\n");

	message_vision(HIR "$N��ָ���壬һ������˿˿�Ĵ��˽�ȥ��\n" NOR, me);

	me->add("max_neili",-10);
	me->set("neili", (int)me->query("max_neili"));
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("learned_points", 2);

	w_zhi = (int)me->query("weapon/value");
	w_zhi++;
	me->set("weapon/value", w_zhi);
	w_or = (string)me->query("weapon/or");
	w_level = (int)me->query("weapon/lv");
	if( w_zhi >= ((w_level + 1) * (w_level + 1)))
	{
		w_level++;
		me->set("weapon/lv", w_level);
		message_vision(HIY "��������һ����һ���������$N�Ĵ��壬�����ˣ�\n" NOR,me);
		message_vision(HIG "$N�Ĵ��ĵȼ�����ˣ�\n" NOR, me);
		weapon=this_object();
		if(weapon->query("equipped") ) 
			weapon->unequip();
		reload_object( weapon );
		me->set("weapon/value",0);
		return 1;
	}
	message_vision(RED "$N�Ĵ���������!\n" NOR, me);
	return 1;
}


int do_hui(object weapon)
{	
	string w_name;
	object me,ob;
	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon )
		return notify_fail("��Ҫ�ݻ�ʲô?\n");
	message_vision(HIR "$N���һ����һ���洸��һ���������¡������¡һ������"
			+w_name+HIR"��Ϊ����!\n" NOR,me);
	me->set("weapon/make",0);
	destruct( this_object() );
	me->delete("weapon");
	
	me->save();

	return 1;
}
/*void owner_is_killed()
{
        write(HIY"ֻ��һ������������"+query("name")+HIY"���ڵ��ϣ��ϳ����ء�\n"NOR);
        this_object()->unequip();
        this_object()->reset_action();
        this_object()->set("name", query("name") + "����Ƭ");
        this_object()->set("value", 0);
        this_object()->set("weapon_prop", 0);
}*/
