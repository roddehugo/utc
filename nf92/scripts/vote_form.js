 $(document).ready(function() {
   $(".input-select").hide();
   
   $(":checkbox").click(function(){
        $(this).parent().next().toggle();
   });

   $("input[type=reset]").click(function(){
   		$(".input-select").hide();
   });

   $(".ajaxForm").submit(function(event) {
    event.preventDefault(); 
	$("#loading-zone").show();
    var $form = $(this);
    var url = $form.attr('action')+'_bdd.php';
	var error = false;
	var nb_vote = $form.find('tbody > tr').length;
	var no_vote = 0;
	$form.find('select[data-type], input[data-type]').each(function(){
		$e = $(this);
		type = $e.attr('data-type');
		val = $e.val();
		switch(type){
			case 'note':
			  	if(val < 0 || val > 10)
			  		error = true;
			 	break;
			case 'no_vote':
			  	if($e.attr("checked") == "checked")
			  		no_vote++;
			  	break;
			default:
			 	console.log("aucun type trouvé");
			  	break;
		}
	});

	if(!error && no_vote < nb_vote){
		$.post(url, $form.serialize(), function(json){
			$("notification").html('<div class="alert alert-'+json.type+'"><button type="button" class="close" data-dismiss="alert">&times;</button>'+json.message+'</div>');
			$("#loading-zone").fadeOut(1000);

		}, "json");
	}else{
		$("notification").html('<div class="alert alert-error"><button type="button" class="close" data-dismiss="alert">&times;</button>Vous devez voter pour au moins une personne, sinon le vote n\'est pas enregistré, et les notes doivent être comprises entre 0 et 10 inclus. Merci.</div>');
		$("#loading-zone").hide();
	}
  });

	$("#loading-zone").fadeOut(1000);

 });
