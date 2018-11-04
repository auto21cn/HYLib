// /u/beyond/mr/guanxingtai.c
// Written by Jpei

inherit ROOM;

int do_look(string arg);
int do_jump(string arg);

void create()
{
	set("short","����̨");
	set("long",@LONG
������С�������������һ����ƽ̨��ƽ̨��Բ�Σ����ϰ���ʮ���޵ķ�
λ�Ų���һЩľ׮������һ����ߵ�ľ׮(zhuang)�Եø���Ĵ�׳��ƽ̨��
��������ӳ������͸����Ҷ�ķ�϶��ƽ̨�������˰ವ����Ӱ��
LONG
);
	set("exits",([
		"south" : __DIR__"xiaojing1-4",
	]) );
	set("outdoors","mr");
	set("no_clean_up",0);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_look", "look");
	add_action("do_look", "lookold");
	add_action("do_look", "l");
}

int do_jump(string arg)
{
	object me = this_player();
	int level, jinglicost;

	level = me->query_skill("dodge");
	if (arg == "zhuang") {
		if (me->query_temp("guanxing_zhuang")) {
			write("���Ѿ���׮���ˣ�����վ����ͷ��ɣ�\n");
			return 1;
		}
		jinglicost = level / 3 + random(level / 4);
		if (me->query("jing") <= jinglicost) {
			write("��̫���ˣ���ЪЪ�ɣ�\n");
			return 1;
		}
		if (level < 250) {
			write("���������ƣ���׮��Ծȥ����ϧ���ǽż⻹��һЩ���ܹ�����\n");
			return 1;
		}
		me->receive_damage("jing", jinglicost);
		message_vision("$N����΢һ�˾��������һ�ݾ�����ľ׮��\n", me);
		me->set_temp("guanxing_zhuang", 1);
		return 1;
	}
	if (arg == "down") {
		if (!me->query_temp("guanxing_zhuang")) {
			message_vision("$N���ڸ�������ȥ������ƽ̨�Ĵ��Ȼ���һ����ȴ��Ȼ�뵽������Ϊ�����ƻ�������ɵ�������������\n", me);
			return 1;
		}
		jinglicost = level / 4 + random(level / 5);
		if (me->query("jing") <= jinglicost) {
			write("��̫���ˣ���ЪЪ�ɣ�\n");
			return 1;
		}
		me->receive_damage("jing", jinglicost);
		if (level < 300)
			message_vision("$N���ֱ��ŵش�׮�ϵ��������������������һ��ƨ�����¡����Ǹ��¡�ʽ��\n", me);
		else
			message_vision("$N����һ���䵽�˵��ϣ��������ľ׮Ҳ̫���ˡ�\n", me);
		me->delete_temp("guanxing_zhuang");
		return 1;
	}
	return notify_fail("��Ҫ����������\n");
}

int do_look(string arg)
{
	object me = this_player();
	mixed *local;
	int i, night, level;

	if (arg == "zhuang") {
		if (me->query_temp("guanxing_zhuang"))
			write("�������µ�ľ׮��ȥ�������е���ѣ���ղ��ڵ��Ͽ�ʱ����û����ô�ߣ�\n");
		else
			write("���ǵ��ϰ��������е�ľ׮�����׳��һ�����ȱ��ľ׮���ߣ�������Ҳ�Ƚ�Զ���Ե���Щ������ġ�\n");
		return 1;
	}
	night = 0;
	local = localtime(time() * 60);
	if (local[2] < 5 || local[2] >= 19) night = 1;

	if (!arg) {
		if (me->query_temp("guanxing_zhuang")) {
			if (local[2] < 3 || local[2] > 22)
				set("long", @LONG
��վ��ľ׮�����Ĵ���������ʱҹɫ��ˮ��������ţ����ܵ��������ѹ
ѹ�Ŀ����������ͷ��ȥ��ҹ��(sky)�ﷱ�ǵ�㣬 һ��һ�����ƺ���������
����ʲô���ܡ��������죬�㾪�ȵط�������̨����ֻ�������������ؿ���
�춥���ǵ��ƶ���
LONG
);
			else if (local[2] < 5)
				set("long", @LONG
��վ��ľ׮�����Ĵ���������ʱ���Ǻ��ҹ�ˣ�����ż�������ļ�������
���������κ����������ܵ��������ѹѹ�Ŀ����������ͷ��ȥ��ҹ��(sky)
�ﷱ�ǵ�㣬һ��һ�����ƺ�������������ʲô���ܡ��������ƣ��㾪�ȵط�
������̨����ֻ�������������ؿ����춥���ǵ��ƶ���
LONG
);
			else if (local[2] > 19)
				set("long", @LONG
��վ��ľ׮�����Ĵ�����������ҹ�������Ѿ��������ˣ�Զ������һ����
�������������ܵ��������ѹѹ�Ŀ����������ͷ��ȥ��ҹ��(sky) �ﷱ�ǵ�
�㣬һ��һ�����ƺ�������������ʲô���ܡ����ö������㾪�ȵط�������̨
����ֻ�������������ؿ����춥���ǵ��ƶ���
LONG
);
			else if (local[2] < 10)
				set("long", @LONG
��վ��ľ׮�����Ĵ������������峿�����ܵ��������Ӱ�ವ���ƺ���Щ
С�������д�����ȥ����ͷ��ȥ�����(sky)����һ�����룬 �����ڴ���ϡ�
�ճ��ĳ�ϼӳ������ߣ��㾪�ȵط�������̨����ֻ�������������ؿ���Զ
������ʡ�
LONG
);
			else if (local[2] < 15)
				set("long", @LONG
��վ��ľ׮�����Ĵ���������������ʱ�֣������������������£������
���Կ������ܵ����ԣ�һЩС�������д�����ȥ����ͷ��ȥ�����(sky) ����
һ�����룬�����ڴ���ϡ�����ֱֱ�����������㾪�ȵط�������̨����ֻ��
�����������ؿ���Զ������ʡ�
LONG
);
			else if (local[2] < 18)
				set("long", @LONG
��վ��ľ׮�����Ĵ��������Ѿ������ˣ������������������£�����¿�
�Կ������ܵ����ԣ�һЩС�������д�����ȥ����ͷ��ȥ�����(sky) ����һ
�����룬�����ڴ���ϡ�������б���㾪�ȵط�������̨����ֻ�����������
���ؿ���Զ������ʡ�
LONG
);
			else
				set("long", @LONG
��վ��ľ׮�����Ĵ�������Զ����Щ�����̣����ܵ��������Ӱ�ವ����
����ЩС�������д�����ȥ����ͷ��ȥ�����(sky)����һ�����룬 �����ڴ�
���ϡ��������Ʋ�Ѥ�������������㾪�ȵط�������̨����ֻ������������
�ؿ���Զ������ʡ�
LONG
);
		}
		else {
			if (local[2] < 3 || local[2] > 22)
				set("long", @LONG
������С�������������һ����ƽ̨��ƽ̨��Բ�Σ����ϰ���ʮ���޵ķ�
λ�Ų���һЩľ׮������һ����ߵ�ľ׮(zhuang)�Եø���Ĵ�׳��ҹɫ��
ˮ���������죬ƽ̨����������ӳ����ҹĻ���Եø�����ɭ��
LONG
);
			else if (local[2] < 5)
				set("long", @LONG
������С�������������һ����ƽ̨��ƽ̨��Բ�Σ����ϰ���ʮ���޵ķ�
λ�Ų���һЩľ׮������һ����ߵ�ľ׮(zhuang)�Եø���Ĵ�׳�����ҹ
�Ŀ��������������£�ƽ̨���ܵ�������ż������������������ҹĻ���Ե���
Щ��ɭ��
LONG
);
			else if (local[2] > 19)
				set("long", @LONG
������С�������������һ����ƽ̨��ƽ̨��Բ�Σ����ϰ���ʮ���޵ķ�
λ�Ų���һЩľ׮������һ����ߵ�ľ׮(zhuang)�Եø���Ĵ�׳���ո���
ҹ��Զ�������и����Ⱥ�����������������ƽ̨���ܵ��������𽥼ž�����
ҹĻ���Ե���Щ��ɭ��
LONG
);
			else if (local[2] < 10)
				set("long",@LONG
������С�������������һ����ƽ̨��ƽ̨��Բ�Σ����ϰ���ʮ���޵ķ�
λ�Ų���һЩľ׮������һ����ߵ�ľ׮(zhuang)�Եø���Ĵ�׳���峿��
��������һ�����������㣬ƽ̨����������ӳ������ǳǳ��͸��ȥ������һƬ
�����ɵġ�
LONG
);
			else if (local[2] < 15)
				set("long",@LONG
������С�������������һ����ƽ̨��ƽ̨��Բ�Σ����ϰ���ʮ���޵ķ�
λ�Ų���һЩľ׮������һ����ߵ�ľ׮(zhuang)�Եø���Ĵ�׳��ƽ̨��
��������ӳ�����������͸����Ҷ�ķ�϶��ƽ̨�������˰ವ����Ӱ��
LONG
);
			else if (local[2] < 18)
				set("long",@LONG
������С�������������һ����ƽ̨��ƽ̨��Բ�Σ����ϰ���ʮ���޵ķ�
λ�Ų���һЩľ׮������һ����ߵ�ľ׮(zhuang)�Եø���Ĵ�׳��ƽ̨��
��������ӳ������������������ԣ����Կ���������ЩС���ڴ�����ȥ��ƽ̨
�ϵ���Ӱ���������ս���ɽ�ˡ�
LONG
);
			else
				set("long",@LONG
������С�������������һ����ƽ̨��ƽ̨��Բ�Σ����ϰ���ʮ���޵ķ�
λ�Ų���һЩľ׮������һ����ߵ�ľ׮(zhuang)�Եø���Ĵ�׳��ƽ̨��
��������ӳ���������������Դ�͸��Ҷ�ķ�϶��ʹ���Կ�������Щ��ɭ��Զ��
��֪˭�ҵĴ���������������������ʱ���ˡ�
LONG
);
		}
		return 0;
	}
	if (arg == "sky") {
		if (!me->query_temp("guanxing_zhuang")) {
			if (night)
				write("���������죬���Ϸ��ǵ�㣬��˳�����ӵķ���ȥ��ȴ���ֲ��ֵ�ҹ�ձ���Χ�����ڵ�ס�ˡ�\n");
			else
				write("���������죬̫����������У����ƶ�䣬����˳���Ʋ�ı�Ե���������������Щ���ۡ�\n");
			return 1;
		}
		if (!night) {
			write("���������죬̫����������У����ƶ�䣬����˳���Ʋ�ı�Ե���������������Щ���ۡ�\n");
			return 1;
		}
		level = me->query_skill("douzhuan-xingyi", 1);
		if (level < 200) {
			write("���������죬���Ϸ��ǵ�㣬���ƺ������Ƕ����ƶ�������ѧ�ġ���ת���ơ���Ī�����ϵ��ȴ�޷���ᡣ\n");
			return 1;
		}
		if (level * level * level / 10 > me->query("combat_exp")) {
			write("���������죬���Ϸ��ǵ�㣬���������Ƕ����ƶ�������ѧ�ġ���ת���ơ���Ī�����ϵ��ȴ����ʵս���鲻�㣬�޷����㿴���Ķ�����ʵ����ս��ϵ��һ��\n");
			return 1;
		}
		write("���������죬���Ϸ��ǵ�㣬���������Ƕ����ƶ�������ѧ�ġ���ת���ơ���Ī�����ϵ��\n");
		if (me->is_busy()) {
			write("��ϧ��������æ��������£��޷�ר���о�ҹ���е��Ƕ���\n");
			return 1;
		}

		if (me->is_fighting() ) {
			write("��ϧ����������ս���У��޷�ר���о�ҹ���е��Ƕ���\n");
			return 1;
		}
		if (me->query("jing") < level / 7) {
			write("��ϧ��̫���ˣ��޷����о������о�ҹ���е��Ƕ���\n");
			return 1;
		}
		me->receive_damage("jing", level / 7);
		me->improve_skill("douzhuan-xingyi", me->query("int"));

		write("����������һЩ��ʵս�����ö�ת���Ƶļ��ɡ�\n");
		if (!random(5))
			tell_room(this_object(), me->name() + "վ��ľ׮���������죬���������ʲô��\n", ({me}));
		return 1;
	}
	return 0;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("guanxing_zhuang"))
		return notify_fail("�ȴ�ľ׮��������(down)��˵�ɣ�\n");

	return ::valid_leave(me, dir);
}
