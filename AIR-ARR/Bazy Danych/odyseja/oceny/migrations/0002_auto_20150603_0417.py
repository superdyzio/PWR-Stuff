# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('oceny', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='druzyna',
            name='Wynik_K',
            field=models.FloatField(default=0.0),
        ),
        migrations.AlterField(
            model_name='druzyna',
            name='Wynik_S',
            field=models.FloatField(default=0.0),
        ),
    ]
