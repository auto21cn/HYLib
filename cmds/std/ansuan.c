// ansuan.c ����
//by King 97.05

#include <ansi.h>

mapping default_where = ([
	"n":	"north",
	"s":	"south",
	"e":	"east",
	"w":	"west",
	"nu":	"northup",
	"su":	"southup",
	"eu":	"eastup",
	"wu":	"westup",
	"nd":	"northdown",
	"sd":	"southdown",
	"ed":	"eastdown",
	"wd":	"westdown",
	"ne":	"northeast",
	"nw":	"northwest",
	"se":	"southeast",
	"sw":	"southwest",
	"u":	"up",
	"d":	"down",
]);

mapping default_dirs = ([
	"north":		"����",
	"south":		"�ϱ�",
	"east":			"����",
	"west":			"����",
	"northup":		"����",
	"southup":		"�ϱ�",
	"eastup":		"����",
	"westup":		"����",
	"northdown":		"����",
	"southdown":		"�ϱ�",
	"eastdown":		"����",
	"westdown":		"����",
	"northeast":		"����",
	"northwest":		"����",
	"southeast":		"����",
	"southwest":		"����",
	"up":			"����",
	"down":			"����",
	"enter":		"����",
	"out":			"����",
]);

mapping default_undirs = ([
	"south":		"����",
	"north":		"�ϱ�",
	"west":			"����",
	"east":			"����",
	"southup":		"����",
	"northup":		"�ϱ�",
	"westup":		"����",
	"eastup":		"����",
	"southdown":		"����",
	"northdown":		"�ϱ�",
	"westdown":		"����",
	"eastdown":		"����",
	"southwest":		"����",
	"southeast":		"����",
	"northwest":		"����",
	"northeast":		"����",
	"down":			"����",
	"up":			"����",
	"out":			"����",
	"enter":		"����",
]);

int main(object me, string arg)
{
	string who, where, dir, undir, where_temp;
	object env, old_env;
	mapping exits;
	object target,obj;
	int count;
	string gen;

	if( !arg || sscanf(arg, "%s at %s", who, where_temp)!=2 ) 
		return notify_fail("ָ���ʽ��ansuan <����> at <����>\n");

	env = environment(me);
	old_env = env;
        if (1)
		return notify_fail("����touxi�����!\n");
	if( where_temp == "leitai" )
		return notify_fail("�����ֹ���㡣\n");


	if( !undefinedp(default_where[where_temp]) )
		where = default_where[where_temp];
	else
		where = where_temp;

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
        return notify_fail("������û�������������µ�½!!\n");
//         write("������û�������������µ�½!!\n");
        }

	if( !mapp(exits = env->query("exits")) || undefinedp(exits[where]) )
		return notify_fail("û���������\n");

	if( !objectp(env = find_object(exits[where])) )
	{	call_other(exits[where], "???");
		env = find_object(exits[where]);
	}

	if( env->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if( env->query("outdoors")=="12gong" )
		return notify_fail("��12���ڲ�����ʹ�ð��㡣\n");

	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ����ܴ�\n");


	if( !objectp(target = present(who, env)) )
		return notify_fail("�������û�д��ˡ�\n");

	if( !target->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

        if (userp(target) && !query_heart_beat(target))
        {
         write("������ʲô��\n");
        return notify_fail("������������\n");
//         write("���˲���beg��\n");
        }

	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ����ܰ��㡣\n");

	if( me->is_fighting() )
		return notify_fail("����æ��ս���أ�������˼������ˣ�\n");

	if( !living(target) )
		return notify_fail(target->name() + "���Ѿ������ˣ��㻹�õ��Ű�����\n"); 

	if((int)target->query("age") <= 17 && userp(target))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

	if(target->query_temp("no_kill"))
		return notify_fail("�㲻��ɱ����ˡ�\n");
	if(target->query("no_touxi"))
		return notify_fail("͵Ϯ�۷��ʲô?\n");

	if(target->query("tasknpc"))
		return notify_fail("�������û�д��ˡ�\n");
if (environment(me)->query("magicroom"))
return notify_fail("�˴�����ʹ��͵Ϯ!\n");

if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR
       ||environment(me)->query("magicroom"))
return notify_fail("�˴�����ʹ��͵Ϯ!\n");

if(target->query_temp("owner/id") && target->query_temp("owner/id") != me->query("id"))
		return notify_fail("����˺ͱ��˵������йأ��㲻��ɱ����ˡ�\n");
//	if(me->query("combat_exp") < target->query("combat_exp")/3  && userp(target))
//		return notify_fail("����˼Ҳ���ô�࣬��ʲô��?\n");


//pk����
    if( userp(target) && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(target) && target->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
	if(me->query("combat_exp") > target->query("combat_exp")*3  && userp(target))
		return notify_fail("�˼Һ������ô�࣬�ò��Ű����?\n");

//��սϵͳ
obj=target;
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");
if(  userp(me) && userp(obj) && obj->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");
	

	if( (int)me->query("jing", 1) < 100 )
		return notify_fail("���޷����о��������㲻�˱��ˡ�\n");

	if( !undefinedp(default_dirs[where]) )
		dir = default_dirs[where];
	else
		dir = where;

	if( !undefinedp(default_undirs[where]) )
		undir = default_undirs[where];
	else
		undir = where;

	if(me->query("gender") == "Ů��")
		gen = "ٻӰ";
	else
		gen = "��Ӱ";

	write( CYN"����Ϣ����������������" + dir + "��" + target->name() + "��ȥ��\n"NOR);
	message("vision", CYN"\nһ��" + gen + "��Ȼ��" + dir + "��ȥ��ת�ۼ��ֻص�ԭ����\n\n"NOR, environment(me), me);
	tell_object(target, CYN"\nһ��" + gen + "��Ȼ��" + undir + "����������\n\n"NOR);
	message("vision", CYN"\nһ��" + gen + "��Ȼ��" + undir + "��" + target->name() + "������\n\n"NOR, environment(target), target);

	count = me->query_str();

//	me->set_temp("apply/name", ({gen}));
//	me->set_temp("apply/id", ({"none"}));
//	me->set_temp("apply/short", ({gen}));
//	me->set_temp("apply/long", ({gen}));

	me->move(environment(target));
        me->fight_ob(target);
        target->fight_ob(me);
        me->fight_ob(target);

        me->add_temp("str", count);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon") );
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
	{
		message_vision(CYN"$Nһʱû�з�������$n���˸����ֲ�����\n"NOR, target, me);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon") );
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
	}
	else
	{
		message_vision(CYN"$N����ḻ������ϸ����������$n������\n"NOR, target, me);
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
        me->fight_ob(target);
        target->fight_ob(me);
        me->fight_ob(target);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon") );
	}

	me->add_temp("str", - count);

	if( random(me->query("combat_exp")) < (int)target->query("combat_exp")/5 )
	{
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");

		tell_object(target, CYN"��һ����ԭ����" + me->name() + "�ڰ����ң�\n"NOR);
		write( CYN "���ã���" + target->name() + "�����ˣ�\n"NOR);
		message_vision(CYN"$N�ȵ���$n����Ұ����ң��Ҹ���û�꣡\n"NOR, target, me);
        me->fight_ob(target);
        target->fight_ob(me);
me->fight_ob(target);
//		if( !target->is_killing(me) ) target->kill_ob(me);
		me->start_busy(3);
	}

	else
	{
		message("vision", CYN"\n" + gen + "ת˲������\n\n"NOR, environment(target), me);
		tell_object(me, CYN"\n�������˻�ԭ����\n\n"NOR);

		me->move(old_env);

		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");

		tell_object(target, CYN"��һ���񣬿���ʲô��û������\n"NOR);
		message("vision", CYN"" + target->name() + "һ���֣̿�����֪��˭�ڰ�������\n"NOR, environment(target), target);
		write( CYN "������" + target->name() + "��Ȼû��������\n"NOR);
		write( CYN"����˴��֣�һ���޹������ӡ�\n"NOR);
	}

	me->start_busy(3);
	me->add("jing", -50);
        if( userp(me) )
                log_file("ansuan_player", sprintf("[%s] %s ansuan %s\n",
                        ctime(time()), geteuid(me), target->query("id")));
//                        ctime(time()), geteuid(me), geteuid(target)));
        return 1;
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");

}

int help(object me)
{
write(@HELP
ָ���ʽ : ansuan <����> at <����>

���ָ�����㰵��λ��<����>��<����>��
�������ɹ�������˷��ֲ����㡣����...:)
HELP
    );
    return 1;
}