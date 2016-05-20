$(document).ready(function() {

   $("#inputSelMod").change(function(){
        id = $(this).val();
        if(id > 0){
            $("#delete").attr('data-etu', id).show();
            $("#inputId").val(etudiants[id]['id']);
            $("#inputNom").val(etudiants[id]['nom']);
            $("#inputPrenom").val(etudiants[id]['prenom']);
            $("#inputAge").val(etudiants[id]['age']);
            $("#inputSexe").val(etudiants[id]['sexe']);
            $("#inputBranche").val(etudiants[id]['branche']);
            $("#inputNoteEsp").val(etudiants[id]['note_esp']);
            $("#formMod").show();
        }else{
            $("#formMod").hide();
            $("#inputSelMod").val('null');
        }
   });

   $("#delete").click(function(event){
        event.preventDefault();
        $("#loading-zone").show();
        $e = $(this);
        idetu = $e.attr('data-etu');
        if(idetu > 0){
            $.post("delete_bdd.php", { id: idetu }, function(json){
                $("notification").html('<div class="alert alert-'+json.type+'"><button type="button" class="close" data-dismiss="alert">&times;</button>'+json.message+'</div>');
                etudiants[idetu] = null;
                $("button[type=reset]").trigger('click');
                $("#formMod").hide();
                $("#inputSelMod").find('option[value='+idetu+']').remove();
                $("#inputSelMod").val('null');
                $("#loading-zone").fadeOut(1000);
            }, "json");
        }else{
            $("#loading-zone").hide();
        }
   })

   $(".ajaxForm").submit(function(event) {
    event.preventDefault(); 
    $("#loading-zone").show();
    var $form = $(this);
    var url = $form.attr('action')+'_bdd.php';
    var error = false;

    $form.find('input[data-type]').each(function(){
        $e = $(this);
        type = $e.attr('data-type');
        val = $e.val();
        switch(type){
            case 'varchar':
                if(!val.match(/^[a-zA-Z .'-àáâãäåçèéêëìíîïðòóôõöùúûüýÿ]+$/i))
                    error = true;
                break;
            case 'age':
                if(val < 7 || val > 77)
                    error = true;
                break;
            case 'note_esp':
                if(val < 0 || val > 500)
                    error = true;
                break;
            default:
                console.log("aucun type trouvé");
                break;
        }
    });
    if(!error){
        $.post(url, $form.serialize(), function(json){
            $("notification").html('<div class="alert alert-'+json.type+'"><button type="button" class="close" data-dismiss="alert">&times;</button>'+json.message+'</div>');
        }, "json");
        idetu = $("#inputId").val();
        $.getJSON("get_etu.php",{ id: idetu },function(json){
          etudiants[idetu] = json;
          $("#inputSelMod").find("option[value="+idetu+"]").text(json.nom+" "+json.prenom); 

          $("#loading-zone").fadeOut(1000);
        });
    }else{
        $("notification").html('<div class="alert alert-error"><button type="button" class="close" data-dismiss="alert">&times;</button>Veuillez vérifier les valeurs entrées : l\'âge doit être compris entre 7 et 77 ans, et la note espérée entre 0 et 500. Merci.</div>');
        $("#loading-zone").hide();
    }
    
  });

    $("#loading-zone").fadeOut(1000);

 });
