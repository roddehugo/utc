<?php
$css_for_layout = 'marketing';
$script_for_layout = '404';
$title_for_layout = 'Projet TUC : Tous Unis pour Compiègne';
ob_start();
?>

    <div class="jumbotron">
      <h1 class="sparklemaster">Erreur 404</h1>
      <p class="lead">La page que vous demandez n'est pas disponible.</p>
    </div>

<?php
$content_for_layout = ob_get_contents();
ob_clean();
require 'views/layout.phtml';
?>
