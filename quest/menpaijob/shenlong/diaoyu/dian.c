          // dian.c
#include <ansi.h>;
inherit ROOM;

int piaodown(object me);
int piaoup(object me);
string* haiyu = ({
        "dashayu",
        "dajqy",
        "jqy",
        "dahaiyu",
        "haiyu",
        "xiami"
});

void create()
{
        set("short", "��Ȼ�̰�");
        set("long", @LONG
���ߵ�һ����ʯ��Ȼ�γɵĵ̰��ϣ��̰�һֱ����ĺ����м䣬��ͷ��һ��С
�䣬��ס����ӿ�ĺ��Σ�ǡ���γ�һ��ˮ��ƽ������̶��͸���峺�ĺ�ˮ���㿴��
��β�����������е�������ȥ��
LONG
        );
        set("exits", ([
                        "west" :__DIR__"shankou" ,
                        "east" :__DIR__"dian1" ,
        ]));

        setup();

}

void init()
{
        add_action("do_dy","diaoyu");
        add_action("do_tai","tai");
}

int do_dy(string arg)
{
        object obgan, obhaiyu, me;
        int i;
        me = this_player();
        
        if( me->is_busy() )
                        return notify_fail("����æ���أ�\n");
        if (me->is_fighting()) 
        return notify_fail("���������������!\n");

        if (! (obgan = present("diaoyu gan", me)) )
                return notify_fail("������ô��������ô��\n");
        if ( me->query_temp("fishing") )
                return notify_fail("�㲻�����ڵ���ô��\n");
        if ( ! (obgan->query("yuer")) )
        {
                message_vision("$N�����еĿյ��㹳����ˮ�У����е��꽪̫��֮�緶��\n", me);
                return 1;
        }
        message_vision("$N�����еĵ����һ�ӣ�����ԶԶ��˦����ȥ����Ư������Ư����ˮ�С�\n", me);       
        
        me->set_temp("fishing", 1);
    
        call_out("piaodown", 10+random(10), me);
        
        return 1;
}
        
 
int do_tai(string arg)
{
        object obgan, obhaiyu, me;
        int i, yunum;
int exp,pot;
        me = this_player();
        
        if( me->is_busy() )
                        return notify_fail("����æ���أ�\n");
        if (me->is_fighting()) 
        return notify_fail("���������������!\n");

        if (! (obgan = present("diaoyu gan", me)) )
                return notify_fail("����̧��ʲô��\n");
        if ( ! me->query_temp("fishing") )
        {
                 message_vision("ֻ��$N�����е�������»����˼��£��ͺ������ڷ��񾭡�\n", me);
                  return 1;
        }
        me->delete_temp("fishing");
       if ( ! obgan->query("yuer") )
        {
                  message_vision("ֻ��$N�����е�����͵�����һ̧������ǰ��ֻ��һ�����������㹳��\n", me);
                return 1;
        }
        obgan->delete("yuer");
        if( ! obgan->query("hasfish") )
        {
                message_vision("ֻ��$N�����е�����͵�����һ̧������ǰ�㹳�ϴ��Ű�����򾡣\n",  me);
                return 1;
        }
        obgan->delete("hasfish");
        yunum = me->query_temp("canqi")-random(5);
//       printf("beryunum = %d\n", yunum);
        if( yunum < 0 )
                yunum = 0;
        if( yunum > 5 )
                yunum = 5;
        yunum = 5 -random(yunum);
//        printf("aftyunum = %d\n", yunum);
        me->delete_temp("canqi");
        obhaiyu = new(__DIR__"obj/" + haiyu[yunum]);
        message_vision("ֻ��$N���յ�������һ˦��һ��" + obhaiyu->name()
                        + "������������\n", me);
        obhaiyu->move(me);
exp=8+random(20);    
pot=4+random(10);    
             tell_object(me,HIW"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬"+ chinese_number(pot) + "��Ǳ�ܡ�\n"NOR);
me->start_busy(4);
        return 1;       
}




int piaodown(object me)
{
        object obgan;
        if ( ! me->query_temp("fishing") )
                return 1;
        if (! (obgan = present("diaoyu gan", me)) )
                return 1;
        if ( ! (obgan->query("yuer")) )
                return 1;
        message_vision("ֻ��$N����Ư��ˮ�ж��˼��£��͵�����һ��......\n", me);
        call_out("piaoup", 2, me);
        obgan->set("hasfish", 1);
        if ( ! me->query_temp("canqi") )
                me->set_temp("canqi", 1);
        else if ( me->query_temp("canqi") < 10 )
                me->add_temp("canqi", 1);
        
        return 1;
}

int piaoup(object me)
{
        int odds;
        object obgan;
        obgan = present("diaoyu gan", me);

        if ( ! me->query_temp("fishing") )
                return 1;
    
        odds = me->query_temp("canqi");
        message_vision("ֻ��$N����Ư��ˮ��һ�������͵������˸�������\n", me);
        obgan->delete("hasfish");
        if ( random(odds) >= 2)
                obgan->delete("yuer");
        call_out("piaodown", 2+random(5), me);
        return 1;
}
