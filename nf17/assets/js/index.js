$(function() { 

    var   $modal = $('#myModal')
        , $modalLabel = $('#myModalLabel')
        , $modalBody = $('#myModal .modal-body')
        , m_date = "Une date valide est requise. Au format DD/MM/YYYY."
        , r_date = /^(\d){4}-(\d){2}-(\d){2}$/      
        , m_time = "Une heure valide est requise. Au format HH:MM:SS."
        , m_not_time = "Une heure valide est requise. 00 < heure < 24 , 00 < min | sec < 59. "
        , r_time = /^(\d){2}:(\d){2}:(\d){2}$/
        , m_varchar = "Caractères alphanumériques accentués seulement.\nAu minimum 2 caractères."
        , r_varchar = /^[a-zA-Z0-9 '"-_°éèàâêîôûäëïöüçœ()\[\]{}]{2,255}$/
        , m_email = "Une adresse email valide est requise."
        , r_email = /^[\w.-]+@[\w.-]+\.[a-zA-Z]{2,6}$/
        , m_tel = "Un numéro de téléphone valide est requis. Chiffres pas d'éspaces."
        , r_tel = /^0[1234567](\d{2}){4}$/
        , m_integer = "Un nombre entier positif est requis."
        , r_integer = /^[0-9]+$/
        , $g = $('#grille')
        , reg = new RegExp(":", "g");


    $('#semaine-text').data("semaine",1);

    $('#myModal').on('focusin','.typeahead',function(data){
        $e = $(this);
        id = $e.attr('id');
        $.getJSON('ajax/typeahead/get.php',{value: id},function(data){
            var items = [], others = [];
            $.each(data,function(key,val){
                items.push(val[0]);
                if (id.match(/^ville$/)) {
                    others.push([ val[0], val[1]]);
                }
            });
            $e.typeahead({
                source: items
            });
        });
    });

    $('a.ajaxAdd').on('click',function(event){
        event.preventDefault();
        value = $(this).data().value;

        $modalLabel.text("Ajouter "+value);
        $modalBody.load('elements/form'+value+".php",function(data){
            $modal.modal();
        });

    });

    $('#myModal').on('reset','.ajaxForm',function(data){
        $(this).find('.control-group').map(function(){
                $(this).removeClass('error').removeClass('success');    
                $(this).find(".help-inline").empty();
        });
    });

    $('#myModal').on('submit','.ajaxForm',function(data){
        var main_error = false;
        $modalBody.find('.alert').remove();
        $(this).find('input').map(function(){
            var type = $(this).data().type,
                val = $(this).val(),
                isRequired = $(this).hasClass('required'),
                error = false;

            switch (type) {
                case "varchar":
                    if(!val.match(r_varchar)){
                        error = true;
                        main_error = true;
                        msg = m_varchar;
                    }
                    break;
                case "mail":
                    if(!val.match(r_email)){
                        error = true;
                        main_error = true;
                        msg = m_email;
                    }
                    break;
                case "phone":
                    if(!val.match(r_tel)){
                        error = true;
                        main_error = true;
                        msg = m_tel;
                    }
                    break;
                case "integer":
                    if(!val.match(r_integer)){
                        error = true;
                        main_error = true;
                        msg = m_integer;
                    }
                    break;
                case "date":
                    if(!val.match(r_date)){
                        error = true;
                        main_error = true;
                        msg = m_date;
                    }
                    break;
                case "time":
                    if(!val.match(r_time)){
                        error = true;
                        main_error = true;
                        msg = m_time;
                    }else{
                        var items = val.split(":");
                        if(   (parseInt(items[0]) > 23 || parseInt(items[0]) < 0)
                           || (parseInt(items[1]) > 59 || parseInt(items[1]) < 0)
                           || (parseInt(items[2]) > 59 || parseInt(items[2]) < 0)
                        ){
                            error = true;
                            main_error = true;
                            msg = m_not_time;
                        }
                    }
                    break;
               /* case "bool":
                    if(val != "0" || val != "1"){
                        error = true;
                        main_error = true;
                        msg = "Valeur booléenne attendue."
                    }*/
                default: 
                    console.log("catch type : "+type+" : "+val);
                    break;
            }
            if(error){
                $(this).parents('.control-group').removeClass('success').addClass('error');
                $(this).next(".help-inline").text(msg);
            }else{
                $(this).parents('.control-group').removeClass('error').addClass('success'); 
                $(this).next(".help-inline").empty();
            }

        });

        if(!main_error){
            $.post('ajax/add'+$(this).data().value+".php",$(this).serialize(),function(data){
                $modalBody.prepend(data);
                window.setTimeout(function(){
                    $modalBody.find('.alert').slideUp();
                }, 4000);
                //$('.ajaxForm :reset').trigger('click');

            },'html');
        }

        return false;
    });


//INDEX

    function calculSpan(dh,dm,fh,fm){
        if(dm == 0 && fm == 0){
            nb = (fh-dh)*4;
        }else if(dm != 0 && fm == 0){
            nb = (60-dm)/15 + (fh-dh-1)*4;
        }else if(dm == 0 && fm != 0){
            nb = (60-fm)/15 + (fh-dh)*4;
        }else{
            nb = (60-dm)/15 + (fh-dh-1)*4 + (60-fm)/15;
        }
        return nb;
    }

    function pushin(title,langue,pays,type,day,deb,fin){
        var tdeb = deb.split(reg);
        var tfin = fin.split(reg);
        tdeb[0] = parseInt(tdeb[0]); 
        tfin[0] = parseInt(tfin[0]);

        var a = parseInt(tdeb[1]);
            if (a >= 0 && a < 15){
                a = 0;
            }else if(a >= 15 && a < 30){
                a = 15;
            }else if(a >= 30 && a < 45){
                a = 30;
            }else if(a >= 45 && a < 60){
                a = 45;
            }
        tdeb[1] = a;

        var a = parseInt(tfin[1]);
            if (a >= 0 && a < 15){
                a = 0;
            }else if(a >= 15 && a < 30){
                a = 15;
            }else if(a >= 30 && a < 45){
                a = 30;
            }else if(a >= 45 && a < 60){
                a = 45;
            }
        tfin[1] = a;

        var nbspan = calculSpan(tdeb[0],tdeb[1],tfin[0],tfin[1]);
        $('#grille td.'+day+'.h-'+tdeb[0]+'-'+tdeb[1]).css('overflow','auto').addClass(type).attr('rowspan',nbspan).html('<h4>'+title+'</h4>'+langue+'<br>'+pays);
        for(var i=0;i<nbspan;i++){
            if(i==0){
                j = 15;
            }else if(i%4==0){
                j = 0;
            }
            $('td.'+day+'.h-'+(tdeb[0]+Math.floor(i/4))+'-'+(tdeb[1]+j)).hide();
            j+=15;
        }
    }

    function maj(nom_chaine){
        $("td.jour")
        .removeClass('film').removeClass('documentaire').removeClass('serie').removeClass('journal')
        .attr('rowspan',1)
        .empty()
        .show();

        $.getJSON('ajax/getGrille.php',{"nom_chaine": nom_chaine},function(data){
            if(data !== null){
                for(film in data.films){
                    var afilm = data.films[film];
                    if(afilm.semaine == $('#semaine-text').data("semaine"))                
                        pushin( afilm.nom_film, afilm.langue, afilm.nom_pays, 'film', afilm.jour ,afilm.heure_debut.substr(0,5), afilm.heure_fin.substr(0,5));
                }
                for(serie in data.series){
                    var aserie = data.series[serie];                    
                    pushin( aserie.nom_serie, aserie.langue, aserie.nom_pays, 'serie', aserie.jour ,aserie.heure_debut.substr(0,5), aserie.heure_fin.substr(0,5));
                }
                for(documentaire in data.documentaires){
                    var adocumentaire = data.documentaires[documentaire];                        
                    pushin( adocumentaire.nom_docu, adocumentaire.langue, adocumentaire.nom_pays, 'documentaire', adocumentaire.jour ,adocumentaire.heure_debut.substr(0,5), adocumentaire.heure_fin.substr(0,5));
                }
                for(journal in data.journaux){
                    var ajournal = data.journaux[journal];                    
                    pushin( ajournal.nom_journal, ajournal.langue, ajournal.nom_pays, 'journal', ajournal.jour ,ajournal.heure_debut.substr(0,5), ajournal.heure_fin.substr(0,5));
                }
            }else{
                alert("Pas de grille pour cette chaine.");
            }
        });
    }

    $('a.next').on('click',function (event){
        event.preventDefault();
        $('#semaine-text').data("semaine",$('#semaine-text').data("semaine")+1);
        time += (7*24*3600);
        $('#semaine-text').load('ajax/getDate.php',{time:time},function(data){
            maj($('#chaineForm #grille_id').val());
        });
    });

    $('a.prev').on('click',function (event){
        event.preventDefault();
        $('#semaine-text').data("semaine",$('#semaine-text').data("semaine")-1);
        time -= (7*24*3600);
        $('#semaine-text').load('ajax/getDate.php',{time:time},function(data){
            maj($('#chaineForm #grille_id').val());
        });
    });

    $('#chaineForm #grille_id').change(function (event){
        $('#sidebar').empty();

        $('#sidebar').load('ajax/getSidebar.php',{"nom_chaine": $(this).val()},function(data){

        });

        maj($(this).val());
    });

});
