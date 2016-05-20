$(document).ready(function() {

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

			$("#loading-zone").fadeOut(1000);
		}, "json");
	}else{
		$("notification").html('<div class="alert alert-error"><button type="button" class="close" data-dismiss="alert">&times;</button>Veuillez vérifier les valeurs entrées : l\'âge doit être compris entre 7 et 77 ans, et la note espérée entre 0 et 500. Merci.</div>');
		$("#loading-zone").hide();
	}
	
  });

	$("#loading-zone").fadeOut(1000);

});
